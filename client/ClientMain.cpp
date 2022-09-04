#include "Client.h"

int main(int argc, char* argv[]) {
    // Server constants
    std::string ip_address = "127.0.0.1";
    int port_no = 5556;

    Client client(const_cast<char*>(ip_address.c_str()), port_no);
    client.communicate();
}
