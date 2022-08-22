#include "../socket/Socket.h"
#include <memory>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./Client [unclassified-data-path] [output-path]" << std::endl;
        return 1;
    }

    // Server constants
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    // Create a socket and connect to the serever
    std::unique_ptr<Socket> socket(new Socket);
    socket->connect(ip_address, port_no);

    // Gather the unclassified data, and send it to the server
    std::string line, fileContent;
    std::ifstream inFile(argv[1]);

    while (std::getline(inFile, line)) { fileContent += line + '\n'; }

    inFile.close();
    socket->send(fileContent, socket->sockFd());

    // Receive the classifications from the server, and write them to the desired path
    char buffer[512] = {0};
    socket->recv(buffer, 512, socket->sockFd());

    std::ofstream ostream(argv[2]);
    ostream << buffer;

    // Finish the program
    socket->close();
    return 0;
}