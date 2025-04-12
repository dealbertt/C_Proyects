#include <iostream>
#include <unistd.h>
#include "../header/sorting.hpp"



void bubbleSort(std::vector<array_member> &vector, SDL_Window *window){

    int size = vector.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size - 1); j++){
            if(vector[j].value > vector[j + 1].value){
                array_member aux = vector[j];
                 

                vector[j] = vector[j + 1];
                vector[j].rect.x = aux.rect.x;

                array_member aux2 = vector[j + 1];
                vector[j + 1] = aux;
                vector[j + 1].rect.x = aux2.rect.x;

            }
            highlightValue(vector[j], window);
            displayUpdates(vector, window);
        }
    }
    //The sorting itself works, its now time to actually display it on the screen
    for(int i = 0; i < (int)vector.size(); i++){
        std::cout << "Order: " << vector[i].value << std::endl;
        std::cout << "Rect Height: " << vector[i].rect.h<< std::endl;
        std::cout << "Rect X: " << vector[i].rect.x<< std::endl;

    }
}

