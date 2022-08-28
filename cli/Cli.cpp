#include "Cli.h"

Cli::Cli(DefaultIO* dio, std::vector<Command*>& commands) : m_dio(dio), m_commands(commands) {}

void Cli::start() {
    // Print the menu
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int size = m_commands.size();

    for (int i = 0; i < size; ++i) {
        menu += std::to_string(i + 1) + ". " + m_commands[i]->description();
    }

    menu += std::to_string(size) + ". exit\n";

    while(true) {
        m_dio->write(menu);

        // Execute the chosen command
        int index = -1;

        try {
            index = std::stoi(m_dio->read());
        } catch (const std::exception& e) {
            m_dio->write("Please enter a number");
            continue;
        }

        if (index <= 0 || index > size) {
            m_dio->write("Invalid command");
            continue;
        }

        if (index == size) {
            break;
        }

        m_commands[index]->execute();
    }
}
