#include <iostream>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>

#include "../header/config.hpp"

Config *config;

int loop(SDL_Window *window, SDL_Surface *surface);
int initObjects(SDL_Window **window, SDL_Surface **surface){
    *window = SDL_CreateWindow("Sorting Algorithim Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config->windowWidth, config->windowHeigth, 0);
    if(window == NULL){
        std::cout << "Error while trying to create the window" << std::endl;
        return -1;
    }

    *surface = SDL_GetWindowSurface(*window);
    if(surface == NULL){
        std::cout << "Error while trying to create the window" << std::endl;
        return -1;
    }

    return 0;
}

int main(){
    config = readConfiguration("config/config.txt");

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;

    initObjects(&window, &surface);

    SDL_UpdateWindowSurface(window);
    loop(window, surface);
    return 0;
}

int loop(SDL_Window *window, SDL_Surface *surface){
    int x = 0, y = config->windowHeigth;

    for(int i = 0; i < config->numberElements; i++){
        SDL_Rect rect = {x, config->windowHeigth - 500, 15, 500};
        SDL_FillRect(surface, &rect, 0xFFFFFF);
        SDL_UpdateWindowSurface(window);

        x += 17;
    }
    sleep(2);
    return 0;
}
