#ifndef KNN_CLASSIFIER_CLIENTSOCKET_H
#define KNN_CLASSIFIER_CLIENTSOCKET_H

#include "Socket.h"

class ClientSocket : public Socket {
public:
    /**
     * Connect to a server.
     * @param cp a string that represents the ip address of the server
     * @param port the desired port on the server
     */
    void connect(const char* cp, int port) const;

    void send(std::string message) const override;

    std::string recv() override;
};


#endif