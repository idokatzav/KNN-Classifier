#ifndef KNN_CLASSIFIER_SERVERSOCKET_H
#define KNN_CLASSIFIER_SERVERSOCKET_H

#include "Socket.h"
#include "ClientSocket.h"
#include <vector>
#define CLIENT_TIME_OUT_SECONDS 60


/**
 * This class represents a server socket that communicates with others using the TCP protocol.
 */
class ServerSocket : public Socket {
private:
    bool m_isRunning;
    int m_clientSock;
    struct timeval m_timeval;
    fd_set m_rfds;

public:
    /**
     * Constructor.
     * @param socket a client's socket
     */
    ServerSocket(int socket);

    /**
     * @return a value for timeout check
     */
    int getRetVal();

   /**
    * Send a message on the socket.
    * @param message the message to be sent
    */
    void send(std::string message) const override;

    /**
     * Receive a message from the socket.
     */
    std::string recv() override;

    /**
     * @return whether the socket is running
     */
    bool isRunning();

    /**
     * Stop running.
    */
    void stopRunning();

    /**
     * Destructor.
     */
    ~ServerSocket() = default;
};


#endif
