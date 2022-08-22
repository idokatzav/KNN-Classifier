#include "../classifier/Classifier.h"
#include "../classifier/distance/EuclideanDistance.h"
#include "../socket/Socket.h"
#include <memory>

int main() {
    // Server Constants
    const int server_port = 5555;
    const int k = 5;

    // Create a socket, and bind a name to it
    std::unique_ptr<Socket> socket(new Socket);
    socket->bind(server_port);

    // Listen for a connection, and accept it
    socket->listen();
    int client_sock = socket->accept();

    // Receive the unclassified data
    char buffer[512] = {0};
    socket->recv(buffer, 512, client_sock);

    // Create a classifier
    std::unique_ptr<Classifier> classifier(new Classifier(k));
    classifier->initFromFile("../server/Data/Classified.csv");

    // Classify the data, and send the classifications to the client
    std::unique_ptr<Distance> metric(new EuclideanDistance());
    std::string res = classifier->classify(buffer, *metric);

    socket->send(res, client_sock);

    // Finish the program
    socket->close();
    return 0;
}