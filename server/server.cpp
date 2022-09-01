#include "../socket/Socket.h"
#include "../cli/Cli.h"
#include "../cli/io/DefaultIO.h"
#include "../cli/io/StandardIO.h"
#include <memory>

int main() {
    /*// Server Constants
    const int server_port = 5555;
    const int k = 5;

    // Create a socket, and bind a name to it
    std::unique_ptr<Socket> socket(new Socket());
    socket->bind(server_port);

    // Listen for connections
    socket->listen();

    while (true) {
        // Accept a connection
        int client_sock = socket->accept();

        // In case of a timeout
        if (client_sock == -1) {
            break;
        }*/

        // Handle the client
        std::unique_ptr<DefaultIO> dio(new StandardIO());
        std::unique_ptr<Cli> cli(new Cli(&(*dio)));

        cli->start();
    /*}

    // Finish the program
    socket->close();*/

    return 0;
}