#include <iostream>
#include <unistd.h>
#include "../header/sorting.hpp"



void bubbleSort(std::vector<array_member> &vector, SDL_Window *window){

    int size = vector.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size - 1); j++){
            if(vector[j].value > vector[j + 1].value){
                clearValueColumn(vector[j], window);
                clearValueColumn(vector[j + 1], window);

                array_member aux = vector[j];

                vector[j] = vector[j + 1];

                vector[j + 1] = aux;


                updateValueColumn(vector[j], window);
                updateValueColumn(vector[j + 1], window);
            }
            highlightValue(vector[j], window);
        }
    }
    for(int i = 0; i < size; i++){
        std::cout << "Order: " << vector[i].value << std::endl;
    }
}

