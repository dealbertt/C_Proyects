#include <SDL3/SDL_init.h>
#include <SDL3/SDL_timer.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>


#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_hints.h>


#include "../header/config.hpp"
#include "../header/keyboard.hpp"
#include "../header/algorithm.hpp"

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

Config *config;

std::vector<array_member> vector;

int loop(SDL_Window *window, SDL_Renderer *renderer);

BubbleSort *bubbleSort = nullptr;
SelectionSort *selectionSort = nullptr;

int initObjects(SDL_Window **window, SDL_Renderer **renderer, BubbleSort **bubbleSort, SelectionSort **selectionSort){
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
        std::cout << "Error trying to initialize SDL" << std::endl;
        return -1;
    }
 
    //Initialize SDL_mixer
    
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

    (*bubbleSort) = new BubbleSort();
    (*selectionSort) = new SelectionSort();

    SDL_RenderPresent(*renderer);


    signal(SIGINT, exit);
    return 0;
}

int main(){
    config = readConfiguration("config/config.txt"); //load the config.txt into an struct


    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    initObjects(&window, &renderer, &bubbleSort, &selectionSort);

    loop(window, renderer);

    SDL_Quit();
    return 0;
}

int loop(SDL_Window *window, SDL_Renderer *renderer){
    Uint32 lastFrameTime = SDL_GetTicks();
    bool running = true;
    bool stop = false;

    int index = 0;

    initializeArray(window, renderer, vector, lastFrameTime);
    while(running){
        //bubbleSort(vector, window, renderer);
        handleKeyboard(stop);
        if(!stop){
            index = bubbleSort->SortStep(vector, window, renderer);
        }

        if(index == -2){
            showSortedArray(vector, window, renderer, lastFrameTime);
            running = false;
        }
        reDrawScreen(renderer, vector, index, lastFrameTime); 
        //float deltaTime;
    }
    initializeArray(window, renderer, vector, lastFrameTime);
    return 0;
}

void exit(){
    SDL_Quit();
    exit(2);
}
