#include "ServerMain.h"

typedef std::vector<std::pair<std::thread, ServerSocket*>> threadsAndSockets;

/**
 * Run the client command line interface.
 * @param dio the default io for the cli
 * @param activeThreads the number of active threads
 */
void clientCli(DefaultIO* dio, int* activeThreads) {
    (*activeThreads)++;
    std::unique_ptr<Cli> cli(new Cli(dio));
    cli->start();
    (*activeThreads)--;
}

/**
 * Handle the active threads, and close unnecessary ones.
 * @param threads the threads
 */
void handleThreads(threadsAndSockets* threads) {
    int size = threads->size();

    for (int i = 0; i < size; ++i) {
        if (!(*threads)[i].second->isRunning()) {
            (*threads)[i].first.join();
            delete (*threads)[i].second;
            (*threads).erase((*threads).cbegin() + i-- + (size - size--));
        }
    }
}

void ServerMain::bindSocket(int server_port, int socket_fd) {
    // Bind the socket
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (::bind(socket_fd, (struct sockaddr*)& sin, sizeof(sin)) < 0) {
        perror("Error binding m_socket");
    }
}

void ServerMain::ListenForCon(int socket_fd) {
    if (::listen(socket_fd, 5) < 0) {
        perror("Error listening for a connection");
    }
}

int ServerMain::timeout(int socket_fd, int seconds) {
    m_timeval.tv_sec = seconds;
    m_timeval.tv_usec = 0;

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket_fd, &rfds);
    auto retval = select(socket_fd + 1, &rfds, NULL, NULL, &m_timeval);

    return retval;
}

ServerMain::ServerMain() {
    m_timeval.tv_usec = 0;
    m_timeval.tv_sec = 0;
}

int ServerMain::acceptCon(int socket_fd) {
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    return ::accept(socket_fd, (struct sockaddr *) &client_sin, &addr_len);
}

int main() {
    ServerMain* serverMain = new ServerMain();
    // Server Constants
    const int serverPort = 5556;
    const int k = 5;
    // Threads count
    int activeThreads = 0;
    threadsAndSockets threads;
    bool isRunning = true;

    std::thread handlingThreads([](threadsAndSockets* v, const bool* pBoolean) {
        while (*pBoolean) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            handleThreads(v);
        }
    }, &threads, &isRunning);

    // Create a socket, bind it a name and listen for a connection
    int sockFd = socket(AF_INET, SOCK_STREAM, 0);

    serverMain->bindSocket(serverPort, sockFd);

    serverMain->ListenForCon(sockFd);

    while (true) {
        // Add a timeout mechanism
        int retval = serverMain->timeout(sockFd, 60);

        if (retval < 0) {
            perror("Error with the socket!");
        } else if (retval == 0) {
            break;
        }

        // Accept a client
        int clientSocket = serverMain->acceptCon(sockFd);

        if (clientSocket < 0) {
            perror("Error accepting a connection");
        }

        // Handle the client
        auto* serverSocket = new ServerSocket(clientSocket);
        DefaultIO* dio = new SocketIO(*serverSocket);
        threads.emplace_back(std::thread(&clientCli, dio, &activeThreads), serverSocket);
    }

    while (activeThreads) {}

    isRunning = false;
    handlingThreads.join();

    // Finish the program
    close(sockFd);
    delete serverMain;
    return 0;
}
