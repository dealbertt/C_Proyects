#include <SDL3/SDL_oldnames.h>
#include <chrono>
#include <iostream>

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_stdinc.h>

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_keyboard.h>
#include <thread>
#include <csignal>

#include "../header/keyboard.hpp"
#include "../header/config.hpp"


extern Config *config;

int handleKeyboard(bool &stop, std::thread &sortThread){
    SDL_Event event;
    SDL_PollEvent(&event);

    const bool *pressed = SDL_GetKeyboardState(NULL);
    
    if(event.type == SDL_EVENT_KEY_DOWN){
        if (pressed[SDL_SCANCODE_UP]) {
            config->fps += 100;
            std::cout << "New fps" << config->fps << std::endl;
            return 1;
        }else if (pressed[SDL_SCANCODE_DOWN] && config->fps > 100) {
            config->fps -= 100;
            std::cout << "New fps" << config->fps << std::endl;
            return 1;
        }else if(pressed[SDL_SCANCODE_ESCAPE]){
            raise(SIGINT);
            kill(getpid(), SIGINT);
        }
    }
    return 0;
}
