#include <iostream>
#include "StandardIO.h"

std::string StandardIO::read() {
    std::string res;
    std::cin >> res;
    return res;
}

void StandardIO::write(std::string str) {
    std::cout << str << std::endl;
}