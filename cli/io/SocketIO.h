#ifndef KNN_CLASSIFIER_SOCKETIO_H
#define KNN_CLASSIFIER_SOCKETIO_H

#include "DefaultIO.h"
#include "../../socket/Socket.h"

/**
 * This class represents communication via sockets.
 */
class SocketIO : public DefaultIO {
private:
    Socket& m_socket;

public:
    /**
     * Constructor.
     * @param socket a socket
     */
    SocketIO(Socket& socket);

    /**
     * Reads user input and returns it as a string.
     * @return the user input
     */
    std::string read() override;

    /**
     * Writes the given output.
     * @param str the output
     */
    void write(const std::string &str) override;
};

#endif
