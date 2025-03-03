#include <iostream>
#include "header/pad.hpp"

Pad::Pad(int x, int y) : xPos(x), yPos(y){}

void Pad::Initialize(){
    std::cout << " Pad X position: " << xPos << " Pad Y position: " << yPos << std::endl;
    return;
}


