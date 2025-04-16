#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "../header/sorting.hpp"


int swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window, SDL_Renderer *renderer){
    int aux[3];

    clearValueColumn(window, renderer, vector[member1]);
    clearValueColumn(window, renderer, vector[member2]);
    //reDrawScreen(renderer, vector, member1);

    aux[0] = vector[member1].value;
    aux[1] = vector[member1].rect.y;
    aux[2] = vector[member1].rect.h;

    vector[member1].value = vector[member2].value;
    vector[member1].rect.y = vector[member2].rect.y;
    vector[member1].rect.h = vector[member2].rect.h;

    vector[member2].value = aux[0];
    vector[member2].rect.y= aux[1];
    vector[member2].rect.h= aux[2];


    updateValueColumn(window, renderer, vector[member1]);
    updateValueColumn(window, renderer, vector[member2]);
    //reDrawScreen(renderer, vector, member2);

    return 0;
}
void bubbleSort(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    

    int size = vector.size();

    auto a = std::chrono::high_resolution_clock::now();

    int comparison = 0;
    int accesses = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){

            highlightValue(window, renderer, vector[j]);

            if(vector[j].value > vector[j + 1].value){

                swapElements(vector, j, j + 1, window, renderer);
                accesses += 3;
            }
            accesses += 2;
        }
    }

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << " seconds" << std::endl;
    std::cout << "Number of array accesses: " << accesses << std::endl;
    std::cout << "Number of comparisons: " << comparison << std::endl;

    //The sorting itself works, its now time to actually display it on the screen
}

void selectionSort(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer){
    int size = (int)vector.size();

    auto a = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            highlightValue(window, renderer, vector[j]);
            if(vector[j].value < vector[min].value){
                min = j;
            }
        }
        //swap the ith value for the min value
        swapElements(vector, i, min, window, renderer);
    }

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << " seconds" << std::endl;

    showSortedArray(vector, window, renderer);
}

int bubbleSortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer){
    static int i = 0;
    static int j = 0;
    int size = static_cast<int>(vector.size());
    
    if(i == size - 1){
        i = 0;
        j = 0;
        return -1;
    }else{
        if(j >= size - i - 1){
            i++;
            j = 0;
        }

        if(vector[j].value > vector[j + 1].value){
            swapElements(vector, j, j + 1, window, renderer);
            //accesses += 3;
        }
        j++;
        return j;
        
    }
    /*
    for(int i = 0; i < (int)vector.size(); i++){
        
        for(int j = 0; j < (int)vector.size() - 1; j++){

            highlightValue(window, renderer, vector[j]);

            if(vector[j].value > vector[j + 1].value){

                swapElements(vector, j, j + 1, window, renderer);
                //accesses += 3;
            }
            //accesses += 2;
        }
    }
    */
    return 0;
}

int selectionSortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer){
    static int i = 0;
    static int j = 0;
    static int min = i;
    int size = static_cast<int>(vector.size());

    //checking if i can go inside of the first for loop
    if(i == size - 1){
        i = -1;
        return i;
        //i cant, meaning i have completed the sorting, so i return -1 to indicate so;
    }else{
        //i can go inside of the first for loop
        //i assign min to i;

        //then i declare the value of j, to go inside of the second for loop
        //j = i + 1;
        if(j < size){
            //this means it can go inside of the second for loop
            if(vector[j].value < vector[min].value){
                min = j;
            }
        j++;
        return j;
        }else{
            //this means that j > size, so i have to increment i and iterate again the first for loop
            i++;
            swapElements(vector, i, min, window, renderer);
            j = i + 1;
        }
    }
    /*
    auto a = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size - 1; i++){
        int min = i;
            for(int j = i + 1; j < size; j++){
            highlightValue(window, renderer, vector[j]);
            if(vector[j].value < vector[min].value){
                min = j;
            }
        }
        //swap the ith value for the min value
        swapElements(vector, i, min, window, renderer);
    }

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << " seconds" << std::endl;
    */


    return 0;
}
