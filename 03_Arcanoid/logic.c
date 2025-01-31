#include "header/logic.h"
#include "header/levels.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include "header/graphics.h"

short BALL_TIMER = 500;
void resetTimer(const short initialValue,short *actualValue){
    *actualValue = initialValue;
    return;
}

bool timer2(TIMER *timer){
    if(timer->value <= 0){
        timer->activated = true;
        timer->value = timer->resetValue;
        return true;
    }else{
        timer->value --;
    }

    return false;
}
bool levelPassed(MAP_t *map){
    if(map->completed){
        return true;
    }else{
        return false;
    }
    return false;
}

void checkBricks(BALL *ball, SDL_Surface *surface){
    if(SDL_MUSTLOCK(surface)){
        SDL_LockSurface(surface);
    }
    
    SDL_UnlockSurface(surface);
    return;
}

bool getPixel(SDL_Surface *surface,int x,int y){
    int pitch = surface->pitch;
    int bpp = surface->format->BytesPerPixel; //Bytes per pixel

    unsigned char *rgb = &surface->pixels[((y * pitch)+(x * bpp))];
    printf("R %d\nG %d\nB %d\n",rgb[0],rgb[1],rgb[2]);

    return false;

}

void updateBallDelta(BALL *ball){
    if(timer2(ball->timer)){
        if(ball->deltaX > 0){

            ball->x += 50;

        }else if(ball->deltaX < 0){
            ball->x -= 50;

        }

        if(ball->deltaY > 0){
            ball->y -= 50;
        }else if(ball->deltaY < 0){
            ball->y += 50;
        }
    }
    return;
}



