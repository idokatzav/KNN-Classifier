#include "Command.h"

Command::Command(DefaultIO *dio, ClassifierData *classifierData) : m_dio(dio), m_classifierData(classifierData) {}

std::string Command::description() const {
    return m_description;
}
