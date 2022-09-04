#ifndef KNN_CLASSIFIER_CLIENT_H
#define KNN_CLASSIFIER_CLIENT_H

#include "../socket/ClientSocket.h"
#include <memory>
#include <thread>

/**
 * This class represents a client communicating with the server.
 */
class Client {
private:
    const std::string m_inputIndicator = "\\Input";
    const std::string m_uploadIndicator = "\\Upload";
    const std::string m_downloadIndicator = "\\Download";
    const std::string m_endOfDownloadIndicator = "\\End";
    int m_port_no;
    char* m_ip_address;
    std::string m_message;
    std::unique_ptr<ClientSocket> m_socket;

    /**
     * @return the user input from the command line.
     */
    static std::string userInput();

    /**
     * Upload command handler.
     */
    void upload();

    /**
     * Download command handler.
     */
    void download();

    /**
    * A general command handler.
    */
    void general();

    /**
     * Write output into a file.
     * @param resultPath the desired path
     * @param output the message to be written
     */
    void writeIntoFile(const std::string& resultPath, const std::string& output);

public:
    /**
     * Constructor
     * @param ip_address the server's ip address
     * @param port_num the server's port
     */
    Client(char* ip_address, int port_num);

    /**
     * Communicate with the server.
     */
    void communicate();
};


#endif
