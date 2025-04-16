#ifndef SORTING_HPP
#define SORTING_HPP

#include "array.hpp"


void bubbleSort(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer);
int bubbleSortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer);
void selectionSort(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer);

int swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window, SDL_Renderer *renderer);
#endif
