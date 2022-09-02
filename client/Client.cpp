#include "Client.h"
#include <iostream>
#include <fstream>

Client::Client(char* ip_address, int port_num) : m_ip_address(ip_address), m_port_no(port_num) {
    m_socket = std::unique_ptr<Socket>(new Socket());
}

std::string Client::userInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Client::upload() {
    m_message.erase(0, m_uploadIndicator.length());

    std::cout << m_message;

    std::string filePath = userInput(), response, line;
    std::ifstream inFile(filePath);

    while (std::getline(inFile, line)) {
        response += line;
    }

    m_socket->send(response);
    std::cout << m_socket->recv();
}

void Client::download() {
    m_message.erase(0, m_downloadIndicator.length());

    std::string resultPath = userInput();

    std::ofstream oFile;
    oFile.open(resultPath + "/results.txt");
    oFile << m_message;
    oFile.close();
}

void Client::general() {
    std::cout << m_message;
    std::string response = userInput();
    m_socket->send(response);
}

void Client::communicate() {
    m_socket->connect(m_ip_address,m_port_no);

    while (true) {
        m_message = m_socket->recv();

        if (m_message == "exit") {
            break;
        }

        if (m_message.find(m_downloadIndicator) < std::string::npos) {
            download();
        } else if (m_message.find(m_uploadIndicator) < std::string::npos) {
            upload();
        } else {
            general();
        }
    }

    m_socket->close();
}
