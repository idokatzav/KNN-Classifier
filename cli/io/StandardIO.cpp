#include <iostream>
#include "StandardIO.h"

std::string StandardIO::read() {
    std::string res;
    getline(std::cin, res);
    return res;
}

void StandardIO::write(const std::string &str) {
    std::cout << str;
}
