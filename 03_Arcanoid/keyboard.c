#include "graphics.h"
#include <stdio.h>

bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad);
bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);

bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad){

    bool quit = false;
    if(timer2(pad->timer)){

        //SDL_WaitEvent(&event);
        SDL_Event event;
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN){

            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:

                    SDL_Quit();
                    printf("QUIT\n");
                    quit = true;
                    return quit;

                    break;

                case SDLK_d:

                    if(pad->x < 875){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x += 25;
                        drawPad(window,surface,pad->x,pad->y);
                    }else{
                        drawPad(window, surface, pad->x, pad->y);
                    }

                    break;
                case SDLK_a:

                    if(pad->x > 25){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x += 25;
                        drawPad(window,surface,pad->x, pad->y);

                    }else{
                        drawPad(window, surface, pad->x , pad->y);
                    }

                    break;
                default:
                    break;

            }
            system("clear");
            printf("X: %d Y: %d\n",pad->x,pad->y);
            printf("Timer: %d\n",pad->timer->value);
        }

    }else{
        SDL_FlushEvent(SDL_KEYDOWN);
    }
    return quit;
}


bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer){

    bool quit = false;
    if(timer2(timer)){

        printf("WORKS\n timer: %hi\n",timer->value);
        //SDL_WaitEvent(&event);

        clearPad(window, surface, *x, *y);
        *x += 50;
        drawPad(window,surface,*x,*y);

    }

     return quit;
}


