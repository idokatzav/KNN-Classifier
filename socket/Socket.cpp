#include "Socket.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

Socket::Socket() {
    // Create the m_socket
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (m_sockfd < 0) {
        perror("Error creating m_socket");
    }
}

int Socket::sockFd() const {
    return m_sockfd;
}

void Socket::bind(int port) const {
    // Bind the m_socket
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    if (::bind(m_sockfd, (struct sockaddr*)& sin, sizeof(sin)) < 0) {
        perror("Error binding m_socket");
    }

    // Add a timeout mechanism
    //TODO: SUS
    struct timeval timeval{};
    timeval.tv_sec = 10;
    timeval.tv_usec = 0;
    setsockopt(m_sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)& timeval, sizeof(timeval));
}

void Socket::connect(const char *cp, int port) const {
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(cp);
    sin.sin_port = htons(port);

    if (::connect(m_sockfd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error initiating a connection");
    }
}

void Socket::listen() const {
    // Listen for a connection, with a queue length of 5
    if (::listen(m_sockfd, 5) < 0) {
        perror("Error listening for a connection");
    }
}

int Socket::accept() const {
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    int client_sock;

    try {
        client_sock = ::accept(m_sockfd, (struct sockaddr *) &client_sin, &addr_len);
    } catch (const std::exception& e) {
        // If a timeout occurred
        return -1;
    }

    if (client_sock < 0) {
        perror("Error accepting a connection");
    }

    return client_sock;
}

void Socket::send(const std::string& message) const {
    if (message.size() > BUFFER_LIM) {
        fprintf(stderr,"Buffer size too big, %d is the character limit", BUFFER_LIM);
    }

    // Mark the message with an End Of Text character
    std::string markedMessage = message + '\003';

    // Send the marked message
    int sent_bytes = ::send(m_sockfd, message.c_str(), message.size(), 0);

    if (sent_bytes < 0) {
        perror("Error sending data");
    }
}

std::string Socket::recv() {
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

void Socket::close() const {
    ::close(m_sockfd);
}