#include "../socket/ServerSocket.h"
#include "../cli/io/SocketIO.h"
#include "../cli/Cli.h"
#include <thread>

void clientCli(std::unique_ptr<DefaultIO> dio, int* activeThreads) {
    (*activeThreads)++;
    std::unique_ptr<Cli> cli(new Cli(dio.get()));
    cli->start();
    (*activeThreads)--;
}

int main() {
    // Server Constants
    const int server_port = 5555;
    const int k = 5;

    // Create a socket, and bind a name to it
    std::unique_ptr<ServerSocket> socket(new ServerSocket());
    socket->bind(server_port);
    int activeThreads = 0;

    // Listen for connections
    socket->listen();

    while (true) {
        auto retval = socket->getRetVal();
        if (retval < 0) {
            perror("Error with the socket!");
        } else if (retval == 0) {
            break;
        }
        // Accept a connection
        int client_sock = socket->accept();

        // In case of a timeout
        if (client_sock == -1) {
            break;
        }

        // Handle the client
        std::unique_ptr<DefaultIO> dio(new SocketIO(*socket));
        std::thread thread1(&clientCli, std::move(dio), &activeThreads);
        thread1.detach();
    }

    while (!activeThreads) {}

    // Finish the program
    socket->close();

    return 0;
}
