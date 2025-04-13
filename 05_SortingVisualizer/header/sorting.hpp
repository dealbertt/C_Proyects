#ifndef SORTING_HPP
#define SORTING_HPP

#include "array.hpp"


void bubbleSort(std::vector<array_member> &vector, SDL_Window *window);
void selectionSort(std::vector<array_member>&vector, SDL_Window *window);

int swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window);
#endif
