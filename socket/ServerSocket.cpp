#include "ServerSocket.h"
#include "Socket.h"
#include <sys/socket.h>
#include <cstring>
#include <algorithm>

ServerSocket::ServerSocket(int socket) : Socket(), m_clientSock(socket), m_isRunning(true) {
    m_timeval.tv_sec = CLIENT_TIME_OUT_SECONDS;
    m_timeval.tv_usec = 0;
    FD_ZERO(&m_rfds);
    FD_SET(m_sockfd, &m_rfds);
}

int ServerSocket::getRetVal() {
    return select(m_sockfd + 1, &m_rfds, NULL, NULL, &m_timeval);
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

bool ServerSocket::isRunning() {
    return m_isRunning;
}

void ServerSocket::stopRunning() {
    m_isRunning = false;
}
