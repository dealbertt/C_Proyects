#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_hints.h>


//Headers created for the program
#include "header/pad.hpp"
#include "header/ball.hpp"
#include "header/graphics.h"
#include "header/timer.hpp"

//First C++ proyect, i am planning on reading books and such to get good at it but i wanted
//to first see what i know and use Chatgpt a little bit to help me on the basics of the language

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"


int initGame(SDL_Window **window, SDL_Surface **surface, Pad **player, Ball **ball){
    
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
    *player = new Pad(500,500);
    *ball = new Ball(500,500,1,1);
    (*ball)->Initialize();
    (*ball)->timer.value = BALL_TIMER_RESET; 
    (*ball)->timer.activated = false;
    std::cout << "Ball timer value:" << (*ball)->timer.value << std::endl;
    (*player)->Initialize();

    (*player)->timer.value = PAD_TIMER_RESET;
    (*player)->timer.activated = false;
    std::cout << "Player timer value:" << (*player)->timer.value << std::endl;

    drawBorders(*window, *surface, BLUE);
    (*ball)->drawBall(*window, *surface, WHITE, true);
    return 0;
}

int main(){
    std::cout << "Hello World\n";
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);



    Ball *ball = nullptr;
    Pad *player = nullptr;

    if (initGame(&window, &surface, &player, &ball) != 0) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return -1;
    }


    SDL_UpdateWindowSurface(window);
    SDL_Delay(1000);
    SDL_Quit();


    return 0;
}

void gameLoop(SDL_Window *window, SDL_Surface *surface, Pad *player, Ball *ball){


}
