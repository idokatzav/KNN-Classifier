#ifndef KNN_CLASSIFIER_CLIENTSOCKET_H
#define KNN_CLASSIFIER_CLIENTSOCKET_H

#include "Socket.h"

/**
 * This class represents a client socket that communicates with others using the TCP protocol.
 */
class ClientSocket : public Socket {
public:
    /**
     * Connect to a server.
     * @param cp a string that represents the ip address of the server
     * @param port the desired port on the server
     */
    void connect(const char* cp, int port) const;

    /**
     * Send a message on the socket.
     * @param message the message to be sent
     */
    void send(std::string message) const override;

    /**
     * Receive a message from the socket.
     */
    std::string recv() override;
};


#endif