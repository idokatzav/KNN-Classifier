#ifndef KNN_CLASSIFIER_SOCKET_H
#define KNN_CLASSIFIER_SOCKET_H

#include <string>

/**
 * This class represents a m_socket that communicates with others using the TCP protocol.
 */
class Socket {
protected:
    static const int BUFFER_LIM = 4096;
    int m_sockfd;

public:
    /**
     * Constructor.
     */
    Socket();

    /**
     * @return the m_socket descriptor
     */
    int sockFd() const;

     /**
      * Send a message on the m_socket.
      * @param message the message to be sent
      */
    virtual void send(std::string message) const = 0;

     /**
      * Receive a message from the m_socket.
      */
    virtual std::string recv() = 0 ;

    /**
     * Close the m_socket.
     */
    void close() const;
};

#endif
