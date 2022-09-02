#include "Client.h"

int main(int argc, char* argv[]) {
    // Server constants
    char* ip_address = "127.0.0.1";
    int port_no = 5555;

    Client client(ip_address, port_no);
    client.communicate();
}