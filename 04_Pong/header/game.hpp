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
        int maxGoals;

        int turn;
        TIMER *timer;

        Pad *player1;
        Pad *player2;
        Ball *ball;
        Game(Pad &player1, Pad &player2, Ball &ball);
        void updateScore();
        float updateGame(SDL_Window *window,const Config &config, Uint32 &lastFrameTime);

        int ballStatus(int values[4]);
        int goalIsScored();
        void resetGame(const Config &config, SDL_Window *window, SDL_Surface *surface);
        TIMER &getTimer() {return *timer;}
        void displayScore(SDL_Surface *mainSurface, SDL_Window *window);
        bool isGameFinished(SDL_Surface *surface, SDL_Window *window);
        
};

#endif


