#include <SFML/Audio/SoundBuffer.hpp>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <signal.h>


#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_hints.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <SFML/Audio.hpp>


#include "../header/config.hpp"
#include "../header/algorithm.hpp"

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

Config *config;

std::vector<array_member> vector;
std::vector<Algorithm *> algorithms;


BubbleSort *bubbleSort = nullptr;
SelectionSort *selectionSort = nullptr;
InsertionSort *insertionSort = nullptr;

sf::SoundBuffer buffer;


int algorithmStateManager(SDL_Window *window, SDL_Renderer *renderer);

int initObjects(SDL_Window **window, SDL_Renderer **renderer){
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
        std::cout << "Error trying to initialize SDL" << std::endl;
        return -1;
    }
    std::cout << "SDL initialized successfully!" << std::endl;
 
    TTF_Init();
    *window = SDL_CreateWindow("Sorting Algorithim Visualizer", config->windowWidth, config->windowHeigth, SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Window created successfully!" << std::endl;

    SDL_SetWindowPosition(*window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    *renderer = SDL_CreateRenderer(*window, NULL);
    SDL_RenderClear(*renderer);
    if(renderer == NULL){
        std::cout << "Error while trying to create the renderer" << std::endl;
        return -1;
        
    }
    std::cout << "Renderer created successfully!" << std::endl;

    bubbleSort = new BubbleSort("Bubble Sort", 0, 0);
    selectionSort = new SelectionSort("Selection Sort", 0, 0);
    insertionSort = new InsertionSort("Insertion Sort", 0, 0);

   
    algorithms.push_back(bubbleSort);
    algorithms.push_back(selectionSort);
    algorithms.push_back(insertionSort);

    std::cout << "Size of algorithms vector: " << algorithms.size() << std::endl;
    signal(SIGINT, exit);

    if(!buffer.loadFromFile("sound/soundEffect.wav")){
        std::cout << "Error while trying to load sound file" << std::endl;
        return -1;
    }
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    sf::sleep(sf::seconds(2)); // or sound.getDuration()

    SDL_RenderPresent(*renderer);
    return 0;
}

int main(){
    config = readConfiguration("config/config.txt"); //load the config.txt into an struct


    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    initObjects(&window, &renderer);


    algorithmStateManager(window, renderer);


    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    delete(bubbleSort);
    delete(selectionSort);
    delete(insertionSort);

    TTF_Quit();
    SDL_Quit();
    return 0;
}


int algorithmStateManager(SDL_Window *window, SDL_Renderer *renderer){
    int index = 0; 

    Uint32 lastFrameTime = SDL_GetTicks();
    while(index < (int)algorithms.size()){
        algorithms[index]->initializeArray(window, renderer, vector, lastFrameTime);
        algorithms[index]->loop(window, renderer, vector, lastFrameTime);
        index++;
    }
    return 0;
}
