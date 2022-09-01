#include "SocketIO.h"

SocketIO::SocketIO(Socket& socket) : m_socket(socket) {}

std::string SocketIO::read() {
    char buf[512];
    m_socket.recv(buf, 512);
    return buf;
}

void SocketIO::write(std::string str) {
    m_socket.send(str);
}

