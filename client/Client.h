#ifndef KNN_CLASSIFIER_CLIENT_H
#define KNN_CLASSIFIER_CLIENT_H

#include "../socket/Socket.h"
#include <memory>

class Client {
private:
    int m_port_no;
    char* m_ip_address;
    const std::string m_uploadIndicator = "\\Upload";
    const std::string m_downloadIndicator = "\\Download";
    std::unique_ptr<Socket> m_socket;
    std::string m_message;

    static std::string userInput();

    void upload();

    void download();

    void general();

public:
    Client(char* ip_address, int port_num);

    void communicate();
};


#endif