#ifndef KNN_CLASSIFIER_SOCKETIO_H
#define KNN_CLASSIFIER_SOCKETIO_H

#include "DefaultIO.h"
#include "../../socket/Socket.h"

class SocketIO : public DefaultIO {
private:
    Socket& m_socket;

public:
    SocketIO(Socket& socket);

    std::string read() override;

    void write(const std::string &str) override;
};

#endif
