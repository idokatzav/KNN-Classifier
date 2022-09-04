#include "Cli.h"
#include "command/UploadCommand.h"
#include "command/SettingsCommand.h"
#include "command/ClassifyCommand.h"
#include "command/DisplayResultsCommand.h"
#include "command/DownloadResultsCommand.h"
#include "command/DisplayConfusionMatrixCommand.h"
#include "io/SocketIO.h"


Cli::Cli(DefaultIO* dio) : m_dio(dio) {
    m_classifierData = new ClassifierData();

    m_commands = {new UploadCommand(m_dio, m_classifierData), new SettingsCommand(m_dio, m_classifierData),
                  new ClassifyCommand(m_dio, m_classifierData), new DisplayResultsCommand(m_dio, m_classifierData),
                  new DownloadResultsCommand(m_dio, m_classifierData), new DisplayConfusionMatrixCommand(m_dio, m_classifierData)};
}

void Cli::start() {
    // Print the menu
    std::string menu = "\\InputWelcome to the KNN Classifier Server. Please choose an option:\n";
    int size = m_commands.size();

    for (int i = 0; i < size; ++i) {
        menu += std::to_string(i + 1) + ". " + m_commands[i]->description() + "\n";
    }

    menu += std::to_string(size + 1) + ". exit\n";

    while(true) {
        m_dio->write(menu);

        // Execute the chosen command
        int index = -1;

        try {
             index = std::stoi(m_dio->read());
        } catch (const std::exception& e) {
            m_dio->write("\\InputPlease enter a number\n");
            continue;
        }

        if (index == size + 1) {
            m_dio->write("exit\n");
            break;
        }

        if (index <= 0 || index > size) {
            m_dio->write("\\InputInvalid command\n");
            continue;
        }

        m_commands[index - 1]->execute();
    }

    try {
        SocketIO* socketIo = (SocketIO*) m_dio;
        socketIo->stopRunning();
    } catch (const std::exception& e) {}
}

Cli::~Cli() {
    delete m_classifierData;
    delete m_dio;

    for (int i = 0; i < m_commands.size(); ++i) {
        delete m_commands[i];
    }
}
