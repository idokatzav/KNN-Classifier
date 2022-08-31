#include "SocketIO.h"

SocketIO::SocketIO(Socket& socket, int sockfd) {
    m_sockfd = sockfd;
    m_socket = socket;
}

std::string SocketIO::read() {
    char buf[512];
    Socket::recv(buf, 512, m_sockfd);
    return buf;
}

void SocketIO::write(std::string str) {
    m_socket.send(str, m_sockfd);
}

