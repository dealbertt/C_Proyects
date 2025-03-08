#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_hints.h>


//Headers created for the program
#include "header/pad.hpp"
#include "header/ball.hpp"
#include "header/graphics.h"
#include "header/timer.hpp"
#include "header/game.hpp"

//First C++ proyect, i am planning on reading books and such to get good at it but i wanted
//to first see what i know and use Chatgpt a little bit to help me on the basics of the language

bool running = true;

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"
void gameLoop(SDL_Window *window, SDL_Surface *surface, Pad *player1, Pad *player2, Ball *ball);


int initGame(SDL_Window **window, SDL_Surface **surface, Pad **player1, Pad **player2, Ball **ball, Game **game){
    
    *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(*window == NULL){
        perror("Error while trying to created SDL Window\n");
        return  -1;
    }

    *surface = SDL_GetWindowSurface(*window);
    if(*surface == NULL){
        perror("Error trying to create SDL_Surface\n");
        return -1;
    }

    *ball = new Ball(BALL_DEFAULT_X, BALL_DEFAULT_Y,1,0);
    (*ball)->deltaX = (*ball)->chooseDelta();
    (*ball)->timer.value = BALL_TIMER_RESET; 
    (*ball)->timer.resetValue = BALL_TIMER_RESET; 
    (*ball)->timer.activated = false;
    (*ball)->drawBall(*window, *surface, WHITE, true);
    (*ball)->Initialize();
    std::cout << "Ball timer value:" << (*ball)->timer.value << std::endl;

    *player1 = new Pad(PLAYER1_DEFAULT_X, PAD_DEFAULT_Y);
    (*player1)->timer.value = PAD_TIMER_RESET;
    (*player1)->timer.activated = false;
    (*player1)->timer.resetValue = PAD_TIMER_RESET;
    (*player1)->Initialize();
    (*player1)->drawPad(*window, *surface);
    std::cout << "Player 1 timer value:" << (*player1)->timer.value << std::endl;

    *player2 = new Pad(PLAYER2_DEFAULT_X, PAD_DEFAULT_Y);
    (*player2)->timer.value = PAD_TIMER_RESET;
    (*player2)->timer.activated = false;
    (*player2)->Initialize();
    (*player2)->drawPad(*window, *surface);
    std::cout << "Player 2 timer value:" << (*player2)->timer.value << std::endl;

    *game = new Game(**player1, **player2, **ball); 

    drawBorders(*window, *surface, BLUE);

    return 0;
}

int main(){
    std::cout << "Hello World\n";
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    
    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    SDL_Init(SDL_INIT_VIDEO);



    Ball *ball = nullptr;
    Pad *player1 = nullptr;
    Pad *player2 = nullptr;
    Game *game = nullptr;

    if (initGame(&window, &surface, &player1, &player2, &ball, &game) != 0) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return -1;
    }


    SDL_UpdateWindowSurface(window);
    gameLoop(window, surface, player1, player2, ball);
    SDL_Delay(1000);
    SDL_Quit();
    delete player1; 
    delete player2; 
    delete ball; 


    return 0;
}

void gameLoop(SDL_Window *window, SDL_Surface *surface, Pad *player1, Pad *player2, Ball *ball){
    while(running){
        //update ball
        ball->clearBall(window, surface);
        ball->updateBall();
        ball->drawBall(window, surface, WHITE, true);

        //moves players
        //check for collisions and stuff i guess
    }

    return;

}
