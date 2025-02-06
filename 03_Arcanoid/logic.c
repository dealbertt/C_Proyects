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
    bool bits[5] = {false,false,false,false,false};
    if(ball->deltaX < 0){
        CollisionStrucutureLeft(bits, ball, surface);

    }else{

        CollisionStrucutureRight(bits, ball, surface);

    }
       //----------------------------- One of this parts need to go to another function

    //case 0 (again)
    if(!bits[1] && !bits[2] && !bits[3]){
        //nothing
        
        system("clear");
        printf("delta x: %d \n deltay: %d\n",ball->deltaX,ball->deltaY);
        return;
    }else if(bits[2]){

        ball->deltaX = -ball->deltaX;
        ball->deltaY = -ball->deltaY;
 
        system("clear");
        printf("delta x: %d \n deltay: %d\n",ball->deltaX,ball->deltaY);
        return;

    }else if(bits[3] && !bits[0] && !bits[1]){

        ball->deltaY = -ball->deltaY;
 
        system("clear");
        printf("delta x: %d \n deltay: %d\n",ball->deltaX,ball->deltaY);
        return;

    }else if(bits[1] && !bits[3] && !bits[4]){

        ball->deltaX = -ball->deltaX;
 
        system("clear");
        printf("delta x: %d \n deltay: %d\n",ball->deltaX,ball->deltaY);
        return;

    }else if(bits[1] && bits[3]){

        ball->deltaX = -ball->deltaX;
        ball->deltaY = -ball->deltaY;
 
        system("clear");
        printf("delta x: %d \n deltay: %d\n",ball->deltaX,ball->deltaY);
        return;

    }



    return;
}

void CollisionStrucutureRight(bool bits[5], BALL *ball, SDL_Surface *surface){
    //bit 0  x + BRICK_WIDTH y + BRICK_HEIGHT
    if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y + BRICK_HEIGHT)){
        //changes to delta
        //apparently no changes to delta (?)
        bits[0] = true;
    }

    //bit 1 x + BRICK_WIDTH y
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y)){
        //changes to delta
        bits[1] = true;
    }
    //bit 2  x + BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[2] = true;
    }

    //bit 3 x y
    else if(getBrickPixel(surface, ball->x, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[3] = true;
    }


    //bit 4 x - BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x - BRICK_WIDTH, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[4] = true;
    }


}

void CollisionStrucutureLeft(bool bits[5], BALL *ball, SDL_Surface *surface){

/*   
 
     2 3 4
     1 b
     0  
     */


    //bit 0  x + BRICK_WIDTH y + BRICK_HEIGHT
    if(getBrickPixel(surface, ball->x - BRICK_WIDTH, ball->y + BRICK_HEIGHT)){
        //changes to delta
        //apparently no changes to delta (?)
        bits[0] = true;
    }

    //bit 1 x + BRICK_WIDTH y
    else if(getBrickPixel(surface, ball->x - BRICK_WIDTH, ball->y)){
        //changes to delta
        bits[1] = true;
    }
    //bit 2  x + BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x - BRICK_WIDTH, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[2] = true;
    }

    //bit 3 x y
    else if(getBrickPixel(surface, ball->x, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[3] = true;
    }


    //bit 4 x - BRICK_WIDTH y - BRICK_HEIGHT
    else if(getBrickPixel(surface, ball->x + BRICK_WIDTH, ball->y - BRICK_HEIGHT)){
        //changes to delta
        bits[4] = true;
    }

    return;


}






