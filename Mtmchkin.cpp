#include <iostream>
#include <string>
#include <fstream>

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string filename) {
    std::ifstream source(filename);
    if(!source) {
        std::cerr << "Invalid file" << std::endl;
    }
}

