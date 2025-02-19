#include "header/logic.h"
#include "header/levels.h"
#include "header/graphics.h"

short BALL_TIMER = 500;
void resetTimer(const short initialValue,short *actualValue){
    *actualValue = initialValue;
    return;
}

bool timer(TIMER *timer){
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
/*

void checkBricks(BALL *ball, SDL_Surface *surface){
    if(SDL_MUSTLOCK(surface)){
        SDL_LockSurface(surface);
    }
    
    SDL_UnlockSurface(surface);
    return;
}
*/
int negateDelta(int delta){
    if(delta > 0){
        delta = -1;
    }else{
        delta = 1;
    }
    return delta;
}

void updateBall(BALL *ball){

    if(timer(ball->timer)){
        if(ball->deltaX > 0){

            ball->x += 15;

        }else if(ball->deltaX < 0){
            ball->x -= 15;

        }

        if(ball->deltaY > 0){
            ball->y -= 15;
        }else if(ball->deltaY < 0){
            ball->y += 15;
        }
    }
    return;
}
