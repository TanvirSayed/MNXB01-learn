//TestNucleus.cpp
#include <iostream>
#include "nucleus.h"
#include <vector>

int main() {
    nucleus flerovium{114,175};
    std::cout<< flerovium.massNum()<<"\n";
    std::cout<< flerovium.radius()<<"\n";
    return flerovium.massNum();
};