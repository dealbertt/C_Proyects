#include "header/collisions.h"
#include "header/graphics.h"
#include "header/logic.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

//NOTE: The x and y positions of rects indicate the top left corner
//Idea behind the collisions
//based on the delta apply a "layer" on the side of the ball that is necessary
//
//  lets say this is the top side of the "ball"(even though its a square but whatever) 
//          ||
//           V 
//  [][][][][][][][][][] this are supposed to be boxes that check the color. if its anything than black, a collision has happened
//  -------------------- 
//  some progress, i still need to figure out how this guys are going to figure out the color tho
bool checkCollisions(SDL_Surface *surface, BALL *ball,SDL_Window *window){
    //check the ball delta to determine where the bits need to be positioned
    LAYER *layer = malloc(sizeof(LAYER));
    if(layer == NULL){
        perror("Error allocating memory for Collision Layer\n");
        return false;
    }
    for(int i = 0; i < 5; i++){
        layer->bits[i] = false;
    }
    assingCheckers(ball,surface,window);



    return false;
}

int assingCheckers(BALL *ball,SDL_Surface *surface,SDL_Window *window){
    //corners only have 4 checkers insted of 5
    if(ball->deltaX == 0 && ball->deltaY < 0){
        //moving only up
        ball->layer->checkers[0] = (SDL_Rect){ball ->x,ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[1] = (SDL_Rect){ball ->x + CHECK_SIZE ,ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[2] = (SDL_Rect){ball ->x + (CHECK_SIZE * 2),ball->y - CHECK_SIZE, CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[3] = (SDL_Rect){ball ->x + (CHECK_SIZE * 3),ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[4] = (SDL_Rect){ball ->x + (CHECK_SIZE * 4),ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        for(int i = 0; i < 5; i++){
            SDL_FillRect(surface, &ball->layer->checkers[i], 0xFFFF0000);
            SDL_UpdateWindowSurface(window);
        }
        //checks for colllisions i guess
        return 1;
    }else if(ball->deltaX == 0 && ball->deltaY < 0){
        //moving only down
        ball->layer->checkers[0] = (SDL_Rect){ball ->x,ball->y + BRICK_HEIGHT,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[1] = (SDL_Rect){ball ->x + CHECK_SIZE ,ball->y + BRICK_HEIGHT,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[2] = (SDL_Rect){ball ->x + (CHECK_SIZE * 2),ball->y + BRICK_HEIGHT, CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[3] = (SDL_Rect){ball ->x + (CHECK_SIZE * 3),ball->y + BRICK_HEIGHT,CHECK_SIZE,CHECK_SIZE,};
        for(int i = 0; i < 5; i++){
            SDL_FillRect(surface, &ball->layer->checkers[i], 0xFFFF0000);
            SDL_UpdateWindowSurface(window);
        }
    }else if(ball->deltaX == 0 && ball->deltaY > 0){
        //moving to the left and up
        ball->layer->checkers[0] = (SDL_Rect){ball ->x,ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[1] = (SDL_Rect){ball ->x + CHECK_SIZE ,ball->y - CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[2] = (SDL_Rect){ball ->x - CHECK_SIZE,ball->y, CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[3] = (SDL_Rect){ball ->x - CHECK_SIZE,ball->y + CHECK_SIZE,CHECK_SIZE,CHECK_SIZE,};
        ball->layer->checkers[4] = (SDL_Rect){ball ->x - CHECK_SIZE,ball->y - CHECK_SIZE ,CHECK_SIZE,CHECK_SIZE,};
        for(int i = 0; i < 5; i++){
            SDL_FillRect(surface, &ball->layer->checkers[i], 0xFFFF0000);
            SDL_UpdateWindowSurface(window);
        }
    }
    return 0;

}
