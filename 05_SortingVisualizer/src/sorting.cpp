#include <SDL3/SDL_video.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "../header/sorting.hpp"

void bubbleSort(std::vector<array_member> &vector, SDL_Window *window){

    int size = vector.size();

    int aux[3];
    auto a = std::chrono::high_resolution_clock::now();

    int comparison = 0;
    int swaps = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){

            highlightValue(vector[j], window);

            if(vector[j].value > vector[j + 1].value){

                clearValueColumn(vector[j], window);
                clearValueColumn(vector[j + 1], window);

                aux[0] = vector[j].value;
                aux[1] = vector[j].rect.y;
                aux[2] = vector[j].rect.h;
                
                vector[j].value = vector[j + 1].value;
                vector[j].rect.y = vector[j + 1].rect.y;
                vector[j].rect.h = vector[j + 1].rect.h;

                vector[j + 1].value = aux[0];
                vector[j + 1].rect.y= aux[1];
                vector[j + 1].rect.h= aux[2];

                updateValueColumn(vector[j], window);
                updateValueColumn(vector[j + 1], window);

                SDL_UpdateWindowSurface(window); //Only updates the surface if a swap is made
                swaps ++;
            }
            comparison++;
        }
    }

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::seconds>(b - a).count() << " seconds" << std::endl;
    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Number of comparisons: " << comparison << std::endl;

    showSortedArray(vector, window);
    //The sorting itself works, its now time to actually display it on the screen
}

