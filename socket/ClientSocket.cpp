#include "ClientSocket.h"
#include "Socket.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdio>

void ClientSocket::connect(const char *cp, int port) const {
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(cp);
    sin.sin_port = htons(port);

    if (::connect(m_sockfd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error initiating a connection");
    }
}

void ClientSocket::send(std::string message) const {
    if (message.size() > BUFFER_LIM) {
        fprintf(stderr,"Buffer size too big, %d is the character limit", BUFFER_LIM);
    }

    // Mark the message with an End Of Text character
    message += '\003';

    // Send the marked message
    char* result = const_cast<char*>(message.c_str());
    int sent_bytes = ::send(m_sockfd, result, strlen(result), 0);

    if (sent_bytes < 0) {
        perror("Error sending data");
    }
}

std::string ClientSocket::recv() {
    std::string response;
    char buf[4096];
    int size = 4096;

    do {
        int read_bytes = ::recv(m_sockfd, buf, size, 0);

        if (read_bytes <= 0) {
            perror("Error receiving data");
        }

        response += buf;
    } while (response[response.length() - 1] != '\003');

    response.pop_back();
    return response;
}
