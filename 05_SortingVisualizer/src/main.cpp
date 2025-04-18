#include <iostream>
#include <unistd.h>
#include <signal.h>


#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_hints.h>

#include "../header/config.hpp"
#include "../header/sorting.hpp"

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

Config *config;

std::vector<array_member> vector;

int loop(SDL_Window *window, SDL_Renderer *renderer);

int initObjects(SDL_Window **window, SDL_Renderer **renderer){
    *window = SDL_CreateWindow("Sorting Algorithim Visualizer", config->windowWidth, config->windowHeigth, SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_SetWindowPosition(*window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);


    *renderer = SDL_CreateRenderer(*window, NULL);
    SDL_RenderClear(*renderer);
    if(renderer == NULL){
        std::cout << "Error while trying to create the renderer" << std::endl;
        return -1;
        
    }

    SDL_RenderPresent(*renderer);

    vector.resize(config->numberElements);

    signal(SIGINT, exit);
    return 0;
}

int main(){
    config = readConfiguration("config/config.txt"); //load the config.txt into an struct

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    initObjects(&window, &renderer);

    loop(window, renderer);

    SDL_Quit();
    return 0;
}

int loop(SDL_Window *window, SDL_Renderer *renderer){
    Uint32 lastFrameTime = SDL_GetTicks();
    bool running = true;

    int index = 0;

    initializeArray(window, renderer, vector);
    while(running){
        //bubbleSort(vector, window, renderer);
        index = bubbleSortStep(vector, window, renderer);

        if(index == -2){
            running = false;
            showSortedArray(vector, window, renderer, lastFrameTime);
        }
        reDrawScreen(renderer, vector, index, lastFrameTime); 
        //float deltaTime;
    }
    return 0;
}

void exit(){
    SDL_Quit();
    exit(2);
}
