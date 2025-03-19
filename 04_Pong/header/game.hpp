#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include "ball.hpp"
#include "pad.hpp"
#include "timer.hpp"
#include "config.hpp"

class Game{
    public:
        int goalsPlayer1;
        int goalsPlayer2;
        int turn;
        TIMER timer;

        Pad *player1;
        Pad *player2;
        Ball *ball;
        Game(Pad &player1, Pad &player2, Ball &ball);
        void updateScore();
        float updateGame(SDL_Window *window, Config config, Uint32 &lastFrameTime);

        int ballStatus(int values[4]);
        int goalIsScored();
        void resetGame(Config config, SDL_Window *window, SDL_Surface *surface);
        void increaseBallSpeed(Config config);
        TIMER &getTimer() {return timer;}
        
};

#endif


