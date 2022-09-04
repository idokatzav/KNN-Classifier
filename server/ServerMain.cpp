#include "../socket/ServerSocket.h"
#include "../cli/Cli.h"
#include "../cli/io/SocketIO.h"
#include <memory>
#include <thread>

void clientCli(std::unique_ptr<DefaultIO> dio) {
    std::unique_ptr<Cli> cli(new Cli(dio.get()));
    cli->start();
}

int main() {
    // Server Constants
    const int server_port = 5555;
    const int k = 5;

    // Create a socket, and bind a name to it
    std::unique_ptr<ServerSocket> socket(new ServerSocket());
    socket->bind(server_port);

    // Listen for connections
    socket->listen();

    while (true) {
        // Accept a connection
        int client_sock = socket->accept();

        // In case of a timeout
        if (client_sock == -1) {
            break;
        }

        // Handle the client
        std::unique_ptr<DefaultIO> dio(new SocketIO(*socket));
        std::thread thread1(&clientCli, std::move(dio));
        thread1.detach();
    }

    // Finish the program
    socket->close();
    return 0;
}
