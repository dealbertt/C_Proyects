#ifndef SORTING_HPP
#define SORTING_HPP

#include "array.hpp"


void bubbleSort(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer);
int bubbleSortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer);

void selectionSort(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer);
int selectionSortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer);

int insertionSortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer);

int swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window, SDL_Renderer *renderer);

//This function, only assigns the value of one member, to the other, instead of swapping the values between the two members
int assignNewElement(std::vector<array_member>&vector, array_member &member1, array_member &member2, SDL_Window *window, SDL_Renderer *renderer);
#endif
