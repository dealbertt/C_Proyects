#include "header/graphics.h"
#include <SDL2/SDL_keycode.h>
#include <stdio.h>

bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,PAD *pad);
//bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);

bool pressToContinue();

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

                    if(pad->x < 875){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x += 25;
                        pad->coordX += 25;
                        pad->center += 25;
                        pad->leftSide+= 25;
                        pad->rightside+= 25;
                        drawPad(window,surface,pad->x,pad->y);
                    }else{
                        drawPad(window, surface, pad->x, pad->y);
                    }

                    break;
                case SDLK_a:

                    if(pad->x > 25){
                        clearPad(window, surface, pad->x, pad->y);
                        pad->x -= 25;
                        pad->coordX -= 25;
                        pad->center -= 25;
                        pad->leftSide -= 25;
                        pad->rightside -= 25;
                        drawPad(window,surface,pad->x, pad->y);

                    }else{
                        drawPad(window, surface, pad->x , pad->y);
                    }

                    break;
                default:
                    break;
            }
            
            system("clear");
            printf("X: %d Y: %d\n",pad->coordX,pad->coordY);
            printf("Timer: %d\n",pad->timer->value);
            printf("Part of the pad:\n");
            printf("LeftSide: %d\n",pad->leftSide);
            printf("Center: %d\n",pad->center);
            printf("RigthSide: %d\n",pad->rightside);
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
