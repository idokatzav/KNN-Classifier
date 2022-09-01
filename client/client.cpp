#include "../socket/Socket.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <string.h>

int main(int argc, char* argv[]) {
    // Server constants
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    // Create a socket and connect to the server
    std::unique_ptr<Socket> socket(new Socket);
    socket->connect(ip_address, port_no);

    while (true) {
        char buf[512];
        socket->recv(buf, 512);

        if (strcmp(buf, "exit") != 0) {
            break;
        }

        // TODO: download command

        std::string response;
        getline(std::cin, response);

        // Check if the input is a file path
        std::ifstream inFile(response);

        if (inFile) {
            response.clear();
            std::string line;

            while (getline(inFile, line)) {
                response += line;
            }

            inFile.close();
        }

        socket->send(response);
    }

    // Finish the program
    socket->close();
}