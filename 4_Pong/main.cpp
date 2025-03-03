#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include "header/pad.hpp"
#include "header/ball.hpp"
#include "header/graphics.hpp"

//First C++ proyect, i am planning on reading books and such to get good at it but i wanted
//to first see what i know and use Chatgpt a little bit to help me on the basics of the language

int main(){
    std::cout << "Hello World\n";
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    Pad player1(0,500);
    Pad player2(900,500);
    
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, 0);
    if(window == NULL){
        perror("Error while trying to created SDL Window\n");
        return  -1;
    }

    surface = SDL_GetWindowSurface(window);
    if(surface == NULL){
        perror("Error trying to create SDL_Surface\n");
        return -1;
    }

    SDL_UpdateWindowSurface(window);
    player1.Initialize();
    player2.Initialize();


    Ball ball(500,500,1,1);
    ball.Initialize();

    return 0;
}
