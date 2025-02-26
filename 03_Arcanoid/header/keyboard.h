#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <SDL2/SDL.h>
#include "logic.h"

bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad);
bool pressToContinue();
#endif 
