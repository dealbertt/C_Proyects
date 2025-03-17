#include "header/game.hpp"
#include "header/graphics.h"
#include "header/pad.hpp"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

Game::Game(Pad &player1, Pad &player2, Ball &ball) : player1(&player1), player2(&player2), ball(&ball){
    goalsPlayer1 = 0;
    goalsPlayer1 = 0;
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
    values[0] = ball->getDeltaX();
    values[1] = ball->getDeltaY();

    //POSITIONS
    values[2] = ball->getX();
    values[3] = ball->getY();
    return 0;
}

int Game::goalIsScored(){
    if((ball->getX() + BRICK_WIDTH) < player1->getXpos()){
        goalsPlayer2++;
        std::cout << "Goal for player 2" << std::endl;
        return 1;
    }else if(ball->getX() > (player2->getXpos() + BRICK_WIDTH)){
        goalsPlayer1++;
        std::cout << "Goal for player 1" << std::endl;
        return 1;
    }
    return 0;
}

void Game::resetGame(Config config, SDL_Window *window, SDL_Surface *surface){
    SDL_Delay(1000);

    ball->clearBall(window, surface);
    ball->setX(config.windowWidth / 2.0f);
    ball->setY(config.windowHeigth / 2.0f);

    player1->clearPad(window, surface);
    player1->setXpos(PLAYER1_DEFAULT_X);

    player2->clearPad(window, surface);
    player2->setXpos(PLAYER2_DEFAULT_X);

    SDL_Rect screen = {config.windowWidth, config.windowHeigth, 0, 0};
    SDL_FillRect(surface, &screen, BLACK);
    SDL_UpdateWindowSurface(window);
    return;
}
