#ifndef KNN_CLASSIFIER_SERVERSOCKET_H
#define KNN_CLASSIFIER_SERVERSOCKET_H

#include "Socket.h"
#define CLIENT_TIME_OUT_SECONDS 60


/**
 * This class represents a server socket that communicates with others using the TCP protocol.
 */
class ServerSocket : public Socket {
private:
    int m_clientSock;
    struct timeval m_timeval;
    fd_set m_rfds;

public:
    /**
     * Constructor.
     */
    ServerSocket();

    /**
     * Bind a name to the socket, and adds a timeout mechanism.
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
     * @return the client's socket fd
     */
    int accept();

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
