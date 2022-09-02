#ifndef KNN_CLASSIFIER_SOCKET_H
#define KNN_CLASSIFIER_SOCKET_H

#include <string>

/**
 * This class represents a m_socket that communicates with others using the TCP protocol.
 */
class Socket {
private:
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
     * Bind a name to the m_socket, and adds a timeout mechanism.
     * @param cp a string that represents the ip address
     * @param port the desired port of the m_socket
     */
    void bind(int port) const;

    /**
     * Connect to a server.
     * @param cp a string that represents the ip address of the server
     * @param port the desired port on the server
     */
    void connect(const char* cp, int port) const;

    /**
     * Listen for a connection.
     */
    void listen() const;

    /**
     * Accept a client.
     * @return the client's m_socket fd
     */
    int accept() const;

     /**
      * Send a message on the m_socket.
      * @param message the message to be sent
      */
    void send(const std::string& message) const;

     /**
      * Receive a message from the m_socket.
      */
    std::string recv() ;

    /**
     * Close the m_socket.
     */
    void close() const;
};

#endif
