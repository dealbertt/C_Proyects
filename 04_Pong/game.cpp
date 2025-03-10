#include "header/game.hpp"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

Game::Game(Pad &player1, Pad &player2, Ball &ball) : player1(player1), player2(player2), ball(ball){
    goalsPlayer1 = 0;
    goalsPlayer1 = 0;
}

void Game::updateScore(){
    if(ball.getX() == 20){
        goalsPlayer2++;
    }else if(ball.getX() == 1000){
        goalsPlayer1++;
    }

}

void Game::updateGame(SDL_Window *window){
    Uint32 frameStart = SDL_GetTicks();

    SDL_UpdateWindowSurface(window);
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
    }

}
