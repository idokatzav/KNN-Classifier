#include "SocketIO.h"

SocketIO::SocketIO(Socket& socket) : m_socket(socket) {}

std::string SocketIO::read() {
    return m_socket.recv();
}

void SocketIO::write(const std::string &str) {
    m_socket.send(str);
}

