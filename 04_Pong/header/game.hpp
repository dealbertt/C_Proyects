#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "ball.hpp"
#include "pad.hpp"
#include "config.hpp"

class Game{
    public:
        int goalsPlayer1;
        int goalsPlayer2;
        int turn;

        Pad player1;
        Pad player2;
        Ball ball;
        Game(Pad &player1, Pad &player2, Ball &ball);
        void updateScore();
        void updateGame(SDL_Window *window, Config config, Uint32 &lastFrameTime);

        int ballStatus(int values[4]);
        
};

#endif


