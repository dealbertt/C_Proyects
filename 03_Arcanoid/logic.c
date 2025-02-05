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

bool getBrickPixel(SDL_Surface *surface,int x,int y){
    //im only getting a pixel here, which sucks, because what i want to check by brick
    // I dont really need to check the whole brick, but rather the part that is going to be bouncing with the ball
    // 
    int pitch = surface->pitch;
    int bpp = surface->format->BytesPerPixel; //Bytes per pixel

    for(int i = 0; i < BRICK_HEIGHT; i++){

        unsigned char *rgb = &surface->pixels[((y * pitch)+(x * bpp))];
        printf("Pixel %d\n",i);
        printf("R %d\nG %d\nB %d\n",rgb[0],rgb[1],rgb[2]);

        x++;
        y++;
        int overall = rgb[0] + rgb[1] + rgb[2];
        /*
        if(overall == 0){
            //true meaning that it has to bounce
            return true;
        }
        */
        if(rgb[0] != 0 || rgb[1] != 0 || rgb[2] != 0){
            return true;
        }

    }
    return false;
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

void getBallColision(BALL *ball,SDL_Surface *surface){

    /*
    Implement the different hit cases 
    
    4 3 2
      b 1
        0 
    */
    //case 0  x + BRICK_WIDTH y + BRICK_HEIGHT
    if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y + BRICK_HEIGHT)){
        //changes to delta
        //apparently no changes to delta (?)
        return;
    }
    //case 1 x + BRICK_WIDTH y
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y)){
        //changes to delta
        ball->deltaX = -1;
        ball->deltaY = -1;
        return;
    }
    //case 2  x + BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y)){
        //changes to delta
        ball->deltaY = -1;
        return;
    }

    //case 3 x y
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y)){
        //changes to delta
        ball->deltaX = -1;
        return;
    }


    //case 4 x - BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y)){
        //changes to delta
        ball->deltaX = -1;
        ball->deltaY = -1;
        return;
    }



    return;
}






