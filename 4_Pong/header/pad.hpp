#ifndef PAD_H
#define PAD_H
#include <iostream>
#include "timer.hpp"


class Pad {
    public:
        int xPos;
        int yPos;
        //timer for movement
        Timer timer;

        Pad(int x, int y);
        void Initialize();
};

#endif 
