#ifndef BALL_HPP
#define BALL_HPP

class Ball {
    public: 
        int xPos;
        int yPos;
        int deltaX;
        int deltaY;
        //include timer for movement
        Ball(int xPos, int yPos, int deltaX, int deltaY);
        void Initialize();
};

#endif

