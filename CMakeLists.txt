cmake_minimum_required(VERSION 3.22)
project(KNN-Classifier)

set(CMAKE_CXX_STANDARD 11)

set(SOCKET
        "socket/Socket.h"
        "socket/Socket.cpp"
)

set(PROJECT_HEADERS
        "classifier/distance/Distance.h"
        "classifier/distance/EuclideanDistance.h"
        "classifier/distance/ManhattanDistance.h"
        "classifier/distance/ChebyshevDistance.h"
        "classifier/Classified.h"
        "classifier/Classifier.h"
        "classifier/Algorithms.h"
        "cli/command/Command.h"
        "cli/IO/DefaultIO.h"
        "cli/IO/SocketIO.h"
        "cli/IO/StandardIO.h"
        "cli/Cli.h"
)

set(PROJECT_SOURCES
        "classifier/distance/EuclideanDistance.cpp"
        "classifier/distance/ManhattanDistance.cpp"
        "classifier/distance/ChebyshevDistance.cpp"
        "classifier/Classified.cpp"
        "classifier/Classifier.cpp"
        "classifier/Algorithms.cpp"
        "cli/IO/SocketIO.cpp"
        "cli/IO/StandardIO.cpp"
        "cli/Cli.cpp"
)

add_executable(Server ${SOCKET} ${PROJECT_HEADERS} ${PROJECT_SOURCES} server/server.cpp)
add_executable(Client ${SOCKET} client/client.cpp)


