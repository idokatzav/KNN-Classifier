#ifndef KNN_CLASSIFIER_SOCKETIO_H
#define KNN_CLASSIFIER_SOCKETIO_H

#include "DefaultIO.h"
#include "../../socket/Socket.h"

class SocketIO : public DefaultIO {
private:
    Socket m_socket;
    int m_sockfd;

public:
    SocketIO(Socket& socket, int sockfd);

    std::string read() override;

    void write(std::string str) override;
};

#endif
