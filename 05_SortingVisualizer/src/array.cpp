#include "../header/array.hpp"
#include "../header/config.hpp"
#include <SDL3/SDL_video.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <random>



extern Config *config;

int initializeArray(SDL_Window *window, std::vector<array_member> &vector){

    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(1, config->windowHeigth - 100); // Generates 0 or 1

    int x = 0;

    int width = config->windowWidth / config->numberElements;
    std::cout << "Optimum width i guess: " << width << std::endl;

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    for(int i = 0; i < (int)vector.size(); i++){
        int guess = dist(gen);
        vector[i].value = guess;
        vector[i].rect  = {x, config->windowHeigth - guess, 8, guess};
        SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFFFFFF);

        x += (width + 2);
    }
    std::cout << "Vector initialized Correctly" << std::endl;
    return 0;
}

int highlightValue(array_member value, SDL_Window *window){
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillSurfaceRect(surface, &value.rect, 0xFFFF0000);
    SDL_UpdateWindowSurface(window);
    //SDL_Delay(50);

    SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    SDL_UpdateWindowSurface(window);
    return 0;
}

int updateValueColumn(array_member &value, SDL_Window *window){

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    SDL_UpdateWindowSurface(window);

    return 0;
}

int clearValueColumn(array_member &value, SDL_Window *window){

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_FillSurfaceRect(surface, &value.rect, 0x00000000);

    return 0;
}


int showSortedArray(std::vector<array_member> &vector, SDL_Window *window){
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    int size = (int)vector.size();

    for(int i = 0; i < size; i++){
        SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFF0000);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }
    std::cout << "Array of size: " << size << " sorted!" << std::endl;
    return 0;
}
