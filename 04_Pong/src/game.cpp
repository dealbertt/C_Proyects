#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "../header/game.hpp"
#include "../header/graphics.h"
#include "../header/pad.hpp"
#include "../header/timer.hpp"

Game::Game(Pad &player1, Pad &player2, Ball &ball) : player1(&player1), player2(&player2), ball(&ball){
    goalsPlayer1 = 0;
    goalsPlayer2 = 0;
    maxGoals = 3;
}

float Game::updateGame(SDL_Window *window,const Config &config, Uint32 &lastFrameTime){
    Uint32 frameStart = SDL_GetTicks();
    float deltaTime = (frameStart - lastFrameTime) / 1000.0f;
    lastFrameTime = frameStart;
    Uint32 frameDelay = 1000 / config.fps;

    SDL_Rect rect = {(WINDOW_WIDTH /2) - 5, 0, 10, WINDOW_HEIGHT};
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, &rect, WHITE);

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
    if(checkTimer(timer) && ball->getSpeed() < player1->getSpeed() + 20){
        float oldSpeed = ball->getSpeed();
        oldSpeed++;
        ball->setSpeed(oldSpeed);
    }

    if((ball->getX() + BRICK_WIDTH) < player1->getXpos()){
        goalsPlayer2++;
        std::cout << "Goal for player 2" << std::endl;
        std::cout << "Score: " << goalsPlayer1 << " - " << goalsPlayer2 << std::endl;
        return 1;
    }else if(ball->getX() > (player2->getXpos() + BRICK_WIDTH)){
        goalsPlayer1++;
        std::cout << "Goal for player 1" << std::endl;
        std::cout << "Score: " << goalsPlayer1 << " - " << goalsPlayer2 << std::endl;
        return 1;
    }
    return 0;
}

void Game::resetGame(const Config &config, SDL_Window *window, SDL_Surface *surface){
    ball->setSpeed(0.0f);
    SDL_Rect screen = {config.windowWidth, config.windowHeigth, 0, 0};
    SDL_FillRect(surface, &screen, BLACK);
    SDL_UpdateWindowSurface(window);

    ball->clearBall(window, surface);
    ball->setDeltaX(0.0f);
    ball->setDeltaY(0.0f);
    ball->setX(config.windowWidth / 2.0f);
    ball->setY(config.windowHeigth / 2.0f);
    std::cout << "Ball x: " << ball->getX() << std::endl;
    std::cout << "Ball y: " << ball->getY() << std::endl;

    player1->clearPad(window, surface);
    player1->setYpos(PAD_DEFAULT_Y);
    player1->drawPad(window, surface, player1->getColor());

    player2->clearPad(window, surface);
    player2->setYpos(PAD_DEFAULT_Y);
    player2->drawPad(window, surface, player2->getColor());
    

    int delta = ball->chooseDelta();
    ball->setDeltaX(delta);
    ball->setDeltaY(1.0f);
    ball->setSpeed(config.ballSpeed);
    ball->drawBall(window, surface, WHITE, false);
    return;
}

void Game::displayScore(SDL_Surface *mainSurface, SDL_Window *window){
    TTF_Init();

    int fontSize = 24;
    SDL_Color textColor = {255, 255, 255};
    std::string fontPath = "fonts/JetBrainsMonoNerdFont-Regular.ttf";
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);

    if(font == NULL){
        std::cerr << "Failed to load the font" << std::endl;
        std::cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
        return;
    }

    std::string score1 = std::to_string(goalsPlayer1);
    std::string score2 = std::to_string(goalsPlayer2);
    std::string totalScore = score1 + "  " + score2;

    SDL_Surface *textSurface = NULL;
    textSurface = TTF_RenderText_Solid(font, totalScore.c_str(), textColor);

    SDL_Rect textRect = {(WINDOW_WIDTH / 2) - 30, 50, 50, 50};

    SDL_BlitSurface(textSurface, NULL, mainSurface, &textRect);

    SDL_FreeSurface(textSurface);

    TTF_CloseFont(font);

    return;
}

bool Game::isGameFinished(SDL_Surface *mainSurface, SDL_Window *window){
    std::string message;
    SDL_Rect rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    if(goalsPlayer1 == maxGoals){
        std::cout << "Player 1 Wins!!" << std::endl;
        message = "Player 1 Wins!!!";
        //red
        SDL_FillRect(mainSurface, &rect, RED);
    }else if(goalsPlayer2 == maxGoals){
        std::cout << "Player 2 Wins!!" << std::endl;
        message = "Player 2 Wins!!!";
        SDL_FillRect(mainSurface, &rect, PURPLE);
    }else{
        return false;
    }

    TTF_Init();

    int fontSize = 24;
    SDL_Color textColor = {0, 0, 0};
    std::string fontPath = "fonts/JetBrainsMonoNerdFont-Regular.ttf";
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);

    if(font == NULL){
        std::cerr << "Failed to load the font" << std::endl;
        std::cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
        return false;
    }

    SDL_Surface *textSurface = NULL;
    textSurface = TTF_RenderText_Solid(font, message.c_str(), textColor);

    SDL_Rect textRect = {(WINDOW_WIDTH / 2) - 30, 50, 50, 50};

    SDL_BlitSurface(textSurface, NULL, mainSurface, &textRect);

    SDL_UpdateWindowSurface(window);

    SDL_FreeSurface(textSurface);

    TTF_CloseFont(font);

    return true;
}
