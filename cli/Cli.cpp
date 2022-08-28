#include "Cli.h"
#include "io/StandardIO.h"
#include "command/UploadCommand.h"
#include "command/SettingsCommand.h"
#include "command/ClassifyCommand.h"
#include "command/DisplayResultsCommand.h"
#include "command/DownloadResultsCommand.h"
#include "command/DisplayConfusionMatrixCommand.h"

Cli::Cli() {
    // TODO: change
    m_dio = std::unique_ptr<DefaultIO>(new StandardIO());

    m_commands = {new UploadCommand(m_dio), new SettingsCommand()};
}

void Cli::start() {

}

Cli::~Cli() {
    for (int i = 0; i < m_commands.size(); ++i) {
        delete m_commands[i];
    }
}
