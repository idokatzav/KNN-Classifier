#include "ServerSocket.h"
#include "Socket.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>
#include <algorithm>


void ServerSocket::bind(int port) const {
    // Bind the socket
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    if (::bind(m_sockfd, (struct sockaddr*)& sin, sizeof(sin)) < 0) {
        perror("Error binding m_socket");
    }

    // TODO: Add a timeout mechanism
}

void ServerSocket::listen() const {
    // Listen for a connection, with a queue length of 5
    if (::listen(m_sockfd, 5) < 0) {
        perror("Error listening for a connection");
    }
}

int ServerSocket::accept() {
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);

    m_clientSock = ::accept(m_sockfd, (struct sockaddr *) &client_sin, &addr_len);

    if (m_clientSock < 0) {
        perror("Error accepting a connection");
    }

    return m_clientSock;
}

void ServerSocket::send(std::string message) const {
    if (message.size() > BUFFER_LIM) {
        fprintf(stderr,"Buffer size too big, %d is the character limit", BUFFER_LIM);
    }

    // Mark the message with an End Of Text character
    message += '\003';

    // Send the marked message
    char* result = const_cast<char*>(message.c_str());
    int sent_bytes = ::send(m_clientSock, result, strlen(result), 0);

    if (sent_bytes < 0) {
        perror("Error sending data");
    }
}

std::string ServerSocket::recv() {
    std::string response;
    char buf[4096] = {0};
    int size = 4096;

    do {
        int read_bytes = ::recv(m_clientSock, buf, size, 0);

        if (read_bytes <= 0) {
            perror("Error receiving data");
        }

        response += buf;

    } while (response[response.length() - 1] != '\003');

    // Remove all occurrences of the End Of Text character
    response.erase(std::remove(response.begin(), response.end(), '\003'), response.end());
    return response;
}
