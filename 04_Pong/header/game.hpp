#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "ball.hpp"
#include "pad.hpp"

class Game{
    public:
        int goalsPlayer1;
        int goalsPlayer2;

        Pad player1;
        Pad player2;
        Ball ball;
        Game(Pad &player1, Pad &player2, Ball &ball);
        void updateScore();
};

#endif


