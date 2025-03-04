#ifndef KEYBOARD_H
#define KEYBOARD_H


#ifndef __cplusplus
extern "C"{
#endif

#include <SDL2/SDL.h>
#include <signal.h>
#include "logic.h"

bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad);
bool pressToContinue();
void handleSignal(int signal);
#endif 
