#include <SDL3/SDL_video.h>
#include <iostream>
#include <unistd.h>
#include "../header/sorting.hpp"



void bubbleSort(std::vector<array_member> &vector, SDL_Window *window){

    int size = vector.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size - 1); j++){
            highlightValue(vector[j], window);
            if(vector[j].value > vector[j + 1].value){
                clearValueColumn(vector[j], window);
                clearValueColumn(vector[j + 1], window);

                int aux[3];
                aux[0] = vector[j].value;
                aux[1] = vector[j].rect.y;
                aux[2] = vector[j].rect.h;
                //array_member aux = vector[j];
                 

                vector[j].value = vector[j + 1].value;
                vector[j].rect.y = vector[j + 1].rect.y;
                vector[j].rect.h = vector[j + 1].rect.h;

                vector[j + 1].value = aux[0];
                vector[j + 1].rect.y= aux[1];
                vector[j + 1].rect.h= aux[2];

                updateValueColumn(vector[j], window);
                updateValueColumn(vector[j + 1], window);
                SDL_UpdateWindowSurface(window);
            }
        }
    }
    displayUpdates(vector, window);
    //The sorting itself works, its now time to actually display it on the screen
    for(int i = 0; i < (int)vector.size(); i++){
        std::cout << "Order: " << vector[i].value << std::endl;
        std::cout << "Rect Height: " << vector[i].rect.h<< std::endl;
        std::cout << "Rect X: " << vector[i].rect.x<< std::endl;

    }
}

