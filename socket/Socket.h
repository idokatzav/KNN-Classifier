#ifndef KNN_CLASSIFIER_SOCKET_H
#define KNN_CLASSIFIER_SOCKET_H

#include <string>

class Socket {
private:
    static const int BUFFER_LIM = 512;
    int m_sockfd;

public:
    /**
     * Constructor.
     */
    Socket();

    /**
     * @return the socket descriptor
     */
    int sockFd() const;

    /**
     * Bind a name to the socket, and adds a timeout mechanism.
     * @param cp a string that represents the ip address
     * @param port the desired port of the socket
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
     * @return the client's socket fd
     */
    int accept() const;

     /**
      * Send a message on a socket.
      * @param message the message to be sent
      * @param socket a socket descriptor
      */
    void send(const std::string& message, int socket) const;

     /**
      * Receive a message from a socket.
      * @param buf the buffer the received message will be written to
      * @param size the size of the buffer
      * @param socket a socket descriptor
      */
    void recv(char* buf, int size, int socket) const;

    /**
     * Close the socket.
     */
    void close() const;
};

#endif
