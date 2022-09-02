#ifndef KNN_CLASSIFIER_SERVERSOCKET_H
#define KNN_CLASSIFIER_SERVERSOCKET_H

#include "Socket.h"

class ServerSocket : public Socket {
private:
    int m_clientSock;

public:
    /**
     * Bind a name to the m_socket, and adds a timeout mechanism.
     * @param cp a string that represents the ip address
     * @param port the desired port of the m_socket
     */
    void bind(int port) const;

    /**
     * Listen for a connection.
     */
    void listen() const;

    /**
     * Accept a client.
     * @return the client's m_socket fd
     */
    int accept();

    void send(std::string message) const override;

    std::string recv() override;
};


#endif
