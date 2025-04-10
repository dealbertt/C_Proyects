#include "../header/array.hpp"
#include "../header/config.hpp"
#include <SDL3/SDL_video.h>
#include <iostream>
#include <unistd.h>
#include <random>



extern Config *config;

int initializeArray(SDL_Window *window){

    array_member array[config->numberElements];

    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(1, config->windowHeigth - 100); // Generates 0 or 1

    int x = 0;

    int width = config->windowWidth / config->numberElements;
    std::cout << "Optimum width i guess: " << width << std::endl;

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    for(int i = 0; i < config->numberElements; i++){
        int guess = dist(gen);
        array[i].rect  = {x, config->windowHeigth - guess, 8, guess};
        SDL_FillSurfaceRect(surface, &array[i].rect, 0xFFFFFF);
        SDL_UpdateWindowSurface(window);

        x += (width + 2);
    }

    for(int i = 0; i < config->numberElements; i++){
        SDL_FillSurfaceRect(surface, &array[i].rect, 0xFFFF0000);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(50);

        SDL_FillSurfaceRect(surface, &array[i].rect, 0xFFFFFFFF);
        SDL_UpdateWindowSurface(window);
        x += (width + 2);
    }
    sleep(4);

    return 0;
}

