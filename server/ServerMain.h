#ifndef KNN_CLASSIFIER_SERVERMAIN_H
#define KNN_CLASSIFIER_SERVERMAIN_H
#include "../socket/ServerSocket.h"
#include "../cli/io/SocketIO.h"
#include "../cli/Cli.h"
#include <thread>
#include <netinet/in.h>
#include <csignal>
#include <cstring>

typedef std::vector<std::pair<std::thread, ServerSocket*>> threadsAndSockets;

class ServerMain {
private:
    struct timeval m_timeval;
public:
    /**
     * Constructor
     */
    ServerMain();

    /**
     * Bind a socket a name.
     * @param server_port the desired port
     * @param socket_fd the socket to be bind
     */
    void bindSocket(int server_port, int socket_fd);

    /**
     * Listen
     * @param socket_fd
     */
    void ListenForCon(int socket_fd);

    /**
     * Create a timeout mechanism for a socket.
     * @param socket_fd the socket
     * @param seconds the number of seconds for the timeout
     * @return a timeout indicator
     */
    int timeout(int socket_fd, int seconds);

    /**
     * Accept a client.
     * @param socket_fd a socket
     * @return the client's socket fd
     */
    int acceptCon(int socket_fd);

    /**
     * Destructor;
     */
    ~ServerMain() = default;
};

#endif
