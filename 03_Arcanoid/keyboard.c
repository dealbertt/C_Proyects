#include "header/graphics.h"
#include <SDL2/SDL_keycode.h>
#include <stdio.h>
#include "header/keyboard.h"

//bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);


bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad){


    bool quit = false;
    if(timer(pad->timer)){

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
                    if(pad->x < WINDOW_WIDTH - BRICK_WIDTH - 100){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x += 30;
                        pad->coordX += 30;
                        pad->center += 30;
                        pad->leftSide+= 30;
                        pad->rightside+= 30;

                        drawPad(window,surface,pad->x,pad->y);
                    }else{
                        drawPad(window, surface, pad->x, pad->y);
                    }

                    break;
                case SDLK_a:

                    if(pad->x > BRICK_WIDTH){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x -= 30;
                        pad->coordX -= 30;
                        pad->center -= 30;
                        pad->leftSide -= 30;
                        pad->rightside -= 30;

                        drawPad(window,surface,pad->x, pad->y);

                    }else{
                        drawPad(window, surface, pad->x , pad->y);
                    }

                    break;
                default:
                    break;
            }
            
        }

    }else{
        SDL_FlushEvent(SDL_KEYDOWN);
    }
    return quit;
}


/*
bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer){

    bool quit = false;
    if(timer(timer)){

        printf("WORKS\n timer: %hi\n",timer->value);
        //SDL_WaitEvent(&event);

        clearPad(window, surface, *x, *y);
        *x += 50;
        drawPad(window,surface,*x,*y);

    }

     return quit;
}
*/

bool pressToContinue(){
         //SDL_WaitEvent(&event);
    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_KEYDOWN){

        if(event.key.keysym.sym == SDLK_SPACE){
            system("clear");
            return true;
        }else{
            return false;
        }
    }else{
        SDL_FlushEvent(SDL_KEYDOWN);
    }
    return false;
    
}
