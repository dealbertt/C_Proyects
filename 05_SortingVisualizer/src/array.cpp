#include "../header/array.hpp"
#include "../header/config.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <random>



extern Config *config;

int initializeArray(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector){

    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(1, config->windowHeigth - 100); // Generates 0 or 1

    float x = 0.0f;

    int width = config->windowWidth / config->numberElements;
    std::cout << "Optimum width i guess: " << width << std::endl;


    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i = 0; i < (int)vector.size(); i++){
        int guess = dist(gen);
        vector[i].value = guess;
        vector[i].rect  = {x, (float)config->windowHeigth - guess, 8, (float)guess};

        reDrawScreen(renderer, vector);
        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFFFFFF);

        x += (width);
    }

    std::cout << "Vector initialized Correctly" << std::endl;
    return 0;
}

int highlightValue(SDL_Window *window, SDL_Renderer *renderer, array_member value){
    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFF0000);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &value.rect);
    //SDL_UpdateWindowSurface(window);

    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    //SDL_UpdateWindowSurface(window);
    
    return 0;
}

int updateValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &value.rect);

    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    //SDL_UpdateWindowSurface(window);

    return 0;
}

int clearValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &value.rect);

    //SDL_FillSurfaceRect(surface, &value.rect, 0x00000000);

    return 0;
}


int showSortedArray(std::vector<array_member> &vector, SDL_Window *window){
    int size = (int)vector.size();

    for(int i = 0; i < size; i++){
        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFF0000);
        //SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }
    std::cout << "Array of size: " << size << " sorted!" << std::endl;
    return 0;
}

int reDrawScreen(SDL_Renderer *renderer, std::vector<array_member> &vector){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int i = 0; i < (int)vector.size(); i++){

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &vector[i].rect);

        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFFFFFF);

    }
    SDL_RenderPresent(renderer);
    return 0;
}

