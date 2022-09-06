#include "Client.h"
#include <iostream>
#include <fstream>

Client::Client(char* ip_address, int port_num) : m_ip_address(ip_address), m_port_no(port_num) {
    m_socket = std::unique_ptr<ClientSocket>(new ClientSocket());
}

std::string Client::userInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Client::upload() {
    m_message.erase(m_message.find(m_uploadIndicator), m_uploadIndicator.length());

    std::cout << m_message;
    m_message.clear();

    std::string filePath = userInput(), response, line;
    std::ifstream inFile(filePath);

    if(!inFile) {
        std::cout << "File doesn't exist\n";
        m_socket->send("\\ERROR");
        return;
    }

    while (std::getline(inFile, line)) {
        response += line + "\n";
    }

    m_socket->send(response);
}

void Client::download() {
    // Extract the data to be downloaded
    int start = m_message.find(m_downloadIndicator) + m_downloadIndicator.length();
    int end =  m_message.find(m_endOfDownloadIndicator);

    std::string result = m_message.substr(start, end - start);

    // Erase it from the message
    m_message.erase(m_message.find(m_downloadIndicator),
                    m_downloadIndicator.length() + result.length() + m_endOfDownloadIndicator.length());

    // Write into the specified file
    std::string resultPath = userInput();
    std::thread thread(&Client::writeIntoFile, this, resultPath + "/results.txt", result);
    thread.detach();

}

void Client::writeIntoFile(const std::string& resultPath, const std::string& output) {
    std::ofstream oFile;
    oFile.open(resultPath);

    oFile << output;
    oFile.close();
}

void Client::general() {
    bool shouldGetInput = false;

    if (m_message.find(m_inputIndicator) < std::string::npos) {
        m_message.erase(m_message.find(m_inputIndicator), m_inputIndicator.length());
        shouldGetInput = true;
    }

    std::cout << m_message;
    m_message.clear();

    if (shouldGetInput) {
        std::string response = userInput();
        m_socket->send(response);
    }
}

void Client::communicate() {
    m_socket->connect(m_ip_address,m_port_no);

    while (true) {
        if (m_message.empty()) {
            m_message = m_socket->recv();
        }

        if (m_message == "exit\n") {
            break;
        }

        if (m_message.find(m_downloadIndicator) < std::string::npos) {
            download();
        } else if (m_message.find(m_uploadIndicator) < std::string::npos) {
            upload();
        } else {
            general();
            m_message.clear();
        }
    }

    m_socket->close();
}