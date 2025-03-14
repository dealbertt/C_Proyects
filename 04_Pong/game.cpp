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

float Game::updateGame(SDL_Window *window, Config config, Uint32 &lastFrameTime){
    Uint32 frameStart = SDL_GetTicks();
    float deltaTime = (frameStart - lastFrameTime) / 1000.0f;
    lastFrameTime = frameStart;
    Uint32 frameDelay = 1000 / config.fps;

    SDL_UpdateWindowSurface(window);
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
    }
    return deltaTime;
}

int Game::ballStatus(int values[4]){
    //DELTAS
    values[0] = ball.getDeltaX();
    values[1] = ball.getDeltaY();

    //POSITIONS
    values[2] = ball.getX();
    values[3] = ball.getY();
    return 0;
}
