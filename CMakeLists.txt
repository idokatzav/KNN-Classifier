cmake_minimum_required(VERSION 3.22)
project(KNN-Classifier)

set(CMAKE_CXX_STANDARD 11)

set(SOCKET
        "socket/Socket.h"
        "socket/Socket.cpp"
        "socket/ClientSocket.h"
        "socket/ClientSocket.cpp"
        "socket/ServerSocket.h"
        "socket/ServerSocket.cpp"
)

set(DISTANCE
        "classifier/distance/Distance.h"
        "classifier/distance/EuclideanDistance.h"
        "classifier/distance/ManhattanDistance.h"
        "classifier/distance/ChebyshevDistance.h"
        "classifier/distance/EuclideanDistance.cpp"
        "classifier/distance/ManhattanDistance.cpp"
        "classifier/distance/ChebyshevDistance.cpp"
)

set(CLASSIFIER
        "classifier/Classified.h"
        "classifier/Classifier.h"
        "classifier/Algorithms.h"
        "classifier/Classified.cpp"
        "classifier/Classifier.cpp"
        "classifier/Algorithms.cpp"
)

set(CLASSIFIER_DATA
        "classifierData/ClassifierData.cpp"
        "classifierData/ClassifierData.h"
)

set(COMMANDS
        "cli/command/Command.h"
        "cli/command/Command.cpp"
        "cli/command/ClassifyCommand.h"
        "cli/command/ClassifyCommand.cpp"
        "cli/command/DisplayConfusionMatrixCommand.h"
        "cli/command/DisplayConfusionMatrixCommand.cpp"
        "cli/command/DisplayResultsCommand.h"
        "cli/command/DisplayResultsCommand.cpp"
        "cli/command/DownloadResultsCommand.h"
        "cli/command/DownloadResultsCommand.cpp"
        "cli/command/SettingsCommand.h"
        "cli/command/SettingsCommand.cpp"
        "cli/command/UploadCommand.h"
        "cli/command/UploadCommand.cpp"
)

set(IO
        "cli/io/DefaultIO.h"
        "cli/io/SocketIO.h"
        "cli/io/SocketIO.cpp"
        "cli/io/StandardIO.h"
        "cli/io/StandardIO.cpp"
)

set(CLI
        "cli/Cli.h"
        "cli/Cli.cpp"
)

set(SERVER
        ${SOCKET}
        ${DISTANCE}
        ${CLASSIFIER}
        ${CLASSIFIER_DATA}
        ${COMMANDS}
        ${IO}
        ${CLI}
        "server/server.cpp"
)

set(CLIENT
        ${SOCKET}
        client/Client.h
        client/Client.cpp
        "client/main.cpp"
)

add_executable(Server ${SERVER})
add_executable(Client ${CLIENT})


