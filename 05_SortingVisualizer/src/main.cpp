#include <iostream>
#include <unistd.h>
#include <signal.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_surface.h>

#include "../header/config.hpp"
#include "../header/sorting.hpp"

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

Config *config;

std::vector<array_member> vector;

int loop(SDL_Window *window, SDL_Surface *surface);

int initObjects(SDL_Window **window, SDL_Surface **surface){
    *window = SDL_CreateWindow("Sorting Algorithim Visualizer", config->windowWidth, config->windowHeigth, 0);

    SDL_SetWindowPosition(*window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    if(window == NULL){
        std::cout << "Error while trying to create the window" << std::endl;
        return -1;
    }

    *surface = SDL_GetWindowSurface(*window);
    if(surface == NULL){
        std::cout << "Error while trying to create the window" << std::endl;
        return -1;
    }

    vector.resize(config->numberElements);

    signal(SIGINT, exit);
    return 0;
}

int main(){
    config = readConfiguration("config/config.txt"); //load the config.txt into an struct

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;

    initObjects(&window, &surface);

    SDL_UpdateWindowSurface(window); //First Update to get the window working

    loop(window, surface);

    SDL_Quit();
    return 0;
}

int loop(SDL_Window *window, SDL_Surface *surface){

    //Array of SDL_Rects and then we can use SDL_FillSurfaceRects to fill them all
    initializeArray(window, vector);
    bubbleSort(vector, window);
    return 0;
}

void exit(){
    SDL_Quit();
    exit(2);
}
