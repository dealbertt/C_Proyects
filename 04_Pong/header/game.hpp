#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "ball.hpp"
#include "pad.hpp"

#define FPS 144
#define frameDelay 1000 / FPS
class Game{
    public:
        int goalsPlayer1;
        int goalsPlayer2;

        Pad player1;
        Pad player2;
        Ball ball;
        Game(Pad &player1, Pad &player2, Ball &ball);
        void updateScore();
        void updateGame(SDL_Window *window);
};

#endif


