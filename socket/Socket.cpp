#include "Socket.h"
#include <sys/socket.h>
#include <unistd.h>

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

void Socket::close() const {
    ::close(m_sockfd);
}