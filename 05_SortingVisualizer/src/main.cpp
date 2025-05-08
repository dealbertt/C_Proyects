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
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Time.hpp>

#include "../header/config.hpp"
#include "../header/algorithm.hpp"

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

Config *config;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;



std::vector<array_member> vector;
std::vector<Algorithm *> algorithms;


BubbleSort *bubbleSort = nullptr;
BidirectionalBubbleSortOptimized *cocktail = nullptr;
BidirectionalBubbleSortUnoptimized *cocktail_bad = nullptr;
SelectionSort *selectionSort = nullptr;
InsertionSort *insertionSort = nullptr;
QuickSort *quicksort = nullptr;

sf::SoundBuffer buffer;

int algorithmStateManager(SDL_Window *window, SDL_Renderer *renderer);
int initObjects(SDL_Window **window, SDL_Renderer **renderer);
void exit();

int main(){
    config = readConfiguration("config/config.txt"); //load the config.txt into an struct

    initObjects(&window, &renderer);

    algorithmStateManager(window, renderer);

    exit();
    return 0;
}

int initObjects(SDL_Window **window, SDL_Renderer **renderer){

    signal(SIGTERM, exit);
    signal(SIGKILL, exit);
    signal(SIGINT, exit);

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
        std::cout << "Error trying to initialize SDL" << std::endl;
        return -1;
    }
    std::cout << "SDL initialized successfully!" << std::endl;
    vector.resize(config->numberElements);
 

    if(!TTF_Init()){
        std::cout << "Error while doing TTF_Init()" << SDL_GetError() << std::endl;
        return -1;
    }

    *window = SDL_CreateWindow("CSort", config->windowWidth, config->windowHeigth, SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_SetWindowPosition(*window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    std::cout << "Window created successfully!" << std::endl;


    *renderer = SDL_CreateRenderer(*window, NULL);
    if(renderer == NULL){
        std::cout << "Error while trying to create the renderer" << std::endl;
        return -1;
        
    }
    SDL_RenderClear(*renderer);
    std::cout << "Renderer created successfully!" << std::endl;

    bubbleSort = new BubbleSort("Bubble Sort", 0, 0);
    cocktail = new BidirectionalBubbleSortOptimized("Cocktail BubbleSort(Optimized)", 0, 0);
    cocktail_bad = new BidirectionalBubbleSortUnoptimized("Cocktail BubbleSort(Normal)", 0, 0);
    selectionSort = new SelectionSort("Selection Sort",  0, 0);
    insertionSort = new InsertionSort("Insertion Sort",  0, 0);
    quicksort = new QuickSort("Quick Sort", 0, 0);


    algorithms.push_back(bubbleSort);
    algorithms.push_back(cocktail_bad);
    algorithms.push_back(cocktail);
    algorithms.push_back(selectionSort);
    algorithms.push_back(insertionSort);
    algorithms.push_back(quicksort);

    std::cout << "Size of algorithms vector: " << algorithms.size() << std::endl;

    if(!buffer.loadFromFile("sound/laser.wav")){
        std::cout << "Error while trying to load sound file" << std::endl;
        return -1;
    }
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    sf::sleep(sf::milliseconds(200)); // or sound.getDuration()
    sound.play();

    SDL_RenderPresent(*renderer);
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

void exit(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    delete(bubbleSort);
    delete(selectionSort);
    delete(insertionSort);
    delete(quicksort);

    TTF_Quit();
    SDL_Quit();
    exit(0);
}


