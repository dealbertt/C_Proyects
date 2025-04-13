#include <SDL3/SDL_video.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "../header/sorting.hpp"


int swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window){
    int aux[3];

    clearValueColumn(vector[member1], window);
    clearValueColumn(vector[member2], window);

    aux[0] = vector[member1].value;
    aux[1] = vector[member1].rect.y;
    aux[2] = vector[member1].rect.h;

    vector[member1].value = vector[member2].value;
    vector[member1].rect.y = vector[member2].rect.y;
    vector[member1].rect.h = vector[member2].rect.h;

    vector[member2].value = aux[0];
    vector[member2].rect.y= aux[1];
    vector[member2].rect.h= aux[2];


    updateValueColumn(vector[member1], window);
    updateValueColumn(vector[member2], window);

    SDL_UpdateWindowSurface(window); //Only updates the surface if a swap is made
    return 0;
}
void bubbleSort(std::vector<array_member> &vector, SDL_Window *window){

    int size = vector.size();

    auto a = std::chrono::high_resolution_clock::now();

    int comparison = 0;
    int swaps = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){

            highlightValue(vector[j], window);

            if(vector[j].value > vector[j + 1].value){

                swapElements(vector, j, j + 1, window);
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

void selectionSort(std::vector<array_member>&vector, SDL_Window *window){
    int size = (int)vector.size();

    auto a = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            highlightValue(vector[j], window);
            if(vector[j].value < vector[min].value){
                min = j;
            }
        }
        //swap the ith value for the min value
        swapElements(vector, min, i, window);
    }
    showSortedArray(vector, window);

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::seconds>(b - a).count() << " seconds" << std::endl;

}


