#ifndef KNN_CLASSIFIER_SOCKETIO_H
#define KNN_CLASSIFIER_SOCKETIO_H

#include "DefaultIO.h"
#include "../../socket/ServerSocket.h"

/**
 * This class represents communication via sockets.
 */
class SocketIO : public DefaultIO {
private:
    ServerSocket& m_socket;

public:
    /**
     * Constructor.
     * @param socket a socket
     */
    SocketIO(ServerSocket& socket);

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

    /**
     * Stop running.
     */
    void stopRunning();
};

#endif
