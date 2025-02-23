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
bool checkCollisions(BALL *ball,SDL_Window *window, PAD *pad){
    //check the ball delta to determine where the bits need to be positioned
    LAYER *layer = malloc(sizeof(LAYER));
    if(layer == NULL){
        perror("Error allocating memory for Collision Layer\n");
        return false;
    }
    for(int i = 0; i < 5; i++){
        ball->layer->bits[i] = false;
    }
    assingCheckers(ball,window,pad);
    return false;
}

int assingCheckers(BALL *ball,SDL_Window *window, PAD *pad){
    //corners do have 5 checkers
    int array[5];
    if(ball->deltaX == 0 && ball->deltaY > 0){
        //moving only up
        array[4] = getColorData(window,ball,ball ->x + (BRICK_WIDTH - CHECK_SIZE * 2),ball->y - CHECK_SIZE - 10,CHECK_SIZE,4);
        array[3] = getColorData(window,ball, ball ->x +(BRICK_WIDTH - CHECK_SIZE) ,ball->y - CHECK_SIZE - 10,CHECK_SIZE,3);
        array[2] = getColorData(window,ball,ball ->x + BRICK_WIDTH,ball->y - CHECK_SIZE, CHECK_SIZE,2);
        array[1] = getColorData(window,ball,ball ->x + BRICK_WIDTH,ball->y,CHECK_SIZE,1);
        array[0] = getColorData(window,ball,ball ->x + BRICK_WIDTH,ball->y + CHECK_SIZE, CHECK_SIZE,0);
        //checks for colllisions i guess
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaY < 0 && ball->y > 900 && ball->x >= pad->x && ball->x <= pad->x + 100){
        array[4] = getColorData(window,ball,ball ->x, ball->y + BRICK_HEIGHT + 10,CHECK_SIZE,4);
        array[3] = getColorData(window,ball, ball ->x + CHECK_SIZE ,ball->y + BRICK_HEIGHT + 10,CHECK_SIZE,3);
        array[2] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 2),ball->y + BRICK_HEIGHT + 10, CHECK_SIZE,2);
        array[1] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 3),ball->y + BRICK_HEIGHT + 10 ,CHECK_SIZE,1);
        array[0] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 4),ball->y + BRICK_HEIGHT + 10 ,CHECK_SIZE,0);
        //checks for colllisions i guess
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDeltaWithPad(ball, pad);
        }
        return 1;
    }else if(ball->deltaX == 0 && ball->deltaY < 0){
        //moving only down
        array[4] = getColorData(window,ball,ball ->x, ball->y + BRICK_HEIGHT + 10,CHECK_SIZE,4);
        array[3] = getColorData(window,ball, ball ->x + CHECK_SIZE ,ball->y + BRICK_HEIGHT + 10,CHECK_SIZE,3);
        array[2] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 2),ball->y + BRICK_HEIGHT + 10, CHECK_SIZE,2);
        array[1] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 3),ball->y + BRICK_HEIGHT + 10 ,CHECK_SIZE,1);
        array[0] = getColorData(window,ball,ball ->x + (CHECK_SIZE * 4),ball->y + BRICK_HEIGHT + 10 ,CHECK_SIZE,0);
        //checks for colllisions i guess
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaX < 0 && ball->deltaY > 0){
        //moving to the left and up
        for(int i = 0; i < 5; i++){
            array[i] = 0;
        }
        array[4] = getColorData(window, ball, ball ->x + CHECK_SIZE, ball->y - CHECK_SIZE - 10,CHECK_SIZE,4);
        array[3] = getColorData(window, ball, ball ->x ,ball->y - CHECK_SIZE - 10,CHECK_SIZE,3);
        array[2] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y - CHECK_SIZE + 10, CHECK_SIZE,2);
        array[1] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y,CHECK_SIZE,1);
        array[0] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y + CHECK_SIZE,CHECK_SIZE,0);
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaX < 0 && ball->deltaY < 0){
        //moving to the left and down
        array[0] = getColorData(window, ball, ball ->x - CHECK_SIZE,ball->y + (BRICK_HEIGHT - (CHECK_SIZE * 2)) + 10,CHECK_SIZE,0);
        array[1] = getColorData(window, ball, ball ->x - CHECK_SIZE,ball->y + (BRICK_HEIGHT - CHECK_SIZE) + 10,CHECK_SIZE,1);
        array[2] = getColorData(window, ball, ball ->x - CHECK_SIZE,ball->y + (BRICK_HEIGHT + 10),CHECK_SIZE,2);
        array[3] = getColorData(window, ball, ball ->x,ball->y + (BRICK_HEIGHT + 10),CHECK_SIZE,3);
        array[4] = getColorData(window, ball, ball ->x + CHECK_SIZE,ball->y + (10 + BRICK_HEIGHT),CHECK_SIZE,4);
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    
    }else if(ball->deltaX > 0 && ball->deltaY < 0){
        //moving to the right and down
        array[4] = getColorData(window, ball, ball ->x + (BRICK_WIDTH - CHECK_SIZE * 2),ball->y + (BRICK_HEIGHT + 10),CHECK_SIZE,4);
        array[3] = getColorData(window, ball, ball ->x + (BRICK_WIDTH - CHECK_SIZE),ball->y + (BRICK_HEIGHT + 10),CHECK_SIZE,3);
        array[2] = getColorData(window, ball, ball ->x + BRICK_WIDTH,ball->y + BRICK_HEIGHT,CHECK_SIZE,2);
        array[1] = getColorData(window, ball, ball ->x + BRICK_WIDTH,ball->y + BRICK_HEIGHT - CHECK_SIZE,CHECK_SIZE,1);
        array[0] = getColorData(window, ball, ball ->x + BRICK_WIDTH,ball->y + (BRICK_HEIGHT - CHECK_SIZE * 2),CHECK_SIZE,0);
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaX > 0 && ball->deltaY > 0){
        //moving to the right and up
        array[4] = getColorData(window,ball,ball ->x + (BRICK_WIDTH - CHECK_SIZE * 2),ball->y - CHECK_SIZE,CHECK_SIZE,4);
        array[3] = getColorData(window,ball, ball ->x +(BRICK_WIDTH - CHECK_SIZE) ,ball->y - CHECK_SIZE,CHECK_SIZE,3);
        array[2] = getColorData(window,ball,ball ->x + BRICK_WIDTH,ball->y - CHECK_SIZE, CHECK_SIZE,2);
        array[1] = getColorData(window,ball,ball ->x + BRICK_WIDTH + 10,ball->y,CHECK_SIZE,1);
        array[0] = getColorData(window,ball,ball ->x + BRICK_WIDTH + 10,ball->y + CHECK_SIZE, CHECK_SIZE,0);
        //checks for colllisions i guess
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaX > 0 && ball->deltaY == 0){
        //moving to the right 
        array[4] = getColorData(window,ball,ball ->x + (BRICK_WIDTH - CHECK_SIZE * 2),ball->y - CHECK_SIZE,CHECK_SIZE,4);
        array[3] = getColorData(window,ball, ball ->x +(BRICK_WIDTH - CHECK_SIZE) ,ball->y - CHECK_SIZE,CHECK_SIZE,3);
        array[2] = getColorData(window,ball,ball ->x + BRICK_WIDTH,ball->y - CHECK_SIZE, CHECK_SIZE,2);
        array[1] = getColorData(window,ball,ball ->x + BRICK_WIDTH + 10,ball->y,CHECK_SIZE,1);
        array[0] = getColorData(window,ball,ball ->x + BRICK_WIDTH + 10,ball->y + CHECK_SIZE, CHECK_SIZE,0);
        //checks for colllisions i guess
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }else if(ball->deltaX < 0 && ball->deltaY == 0){
        //moving just to the left
        array[4] = getColorData(window, ball, ball ->x + CHECK_SIZE, ball->y - CHECK_SIZE ,CHECK_SIZE,4);
        array[3] = getColorData(window, ball, ball ->x ,ball->y - CHECK_SIZE,CHECK_SIZE,3);
        array[2] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y - CHECK_SIZE, CHECK_SIZE,2);
        array[1] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y,CHECK_SIZE,1);
        array[0] = getColorData(window, ball, ball ->x - CHECK_SIZE, ball->y + CHECK_SIZE,CHECK_SIZE,0);
        if(array[0] == 1 || array[1] == 1 || array[2] == 1|| array[3] == 1 || array[4] == 1){
            changeDelta(ball);
        }
        return 1;
    }
    return 0;

}
int getColorData(SDL_Window *window, BALL *ball, int startX, int y,int width,int index){
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    if(surface == NULL){
        printf("Error trying to get the surface from window");
        return -1;
    }
    SDL_LockSurface(surface);
        for (int x = startX; x < startX + width; ++x) {
            // Make sure the coordinates are within the surface bounds
            if (x >= 0 && x < surface->w){
                // Get the pixel value
                Uint32 pixel = ((Uint32*)surface->pixels)[y * surface->w + x];

                // Extract the RGBA values
                Uint8 r, g, b, a;
                SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);

                // Output the color of the pixel
                Uint8 totalColor = r + g + b;
                if(totalColor != 0){
                    ball->layer->bits[index] = true;
                    //printf("R=%d, G=%d, B=%d, A=%d\n", r, g, b, a);
                    SDL_UnlockSurface(surface);
                    return 1;
                }
            }
        }
    SDL_UnlockSurface(surface);

    return 0;
}

void changeDelta(BALL *ball){
     if(!ball->layer->bits[0] && !ball->layer->bits[1] && !ball->layer->bits[2] && !ball->layer->bits[3] && !ball->layer->bits[4]){
        //case 0
        //no collision;
    }else if(ball->layer->bits[2] && !ball->layer->bits[1] && !ball->layer->bits[2]){
        //case 1
        ball->deltaX = -(ball->deltaX);
        ball->deltaY = -(ball->deltaY);
        printf("CASE 1\n");
        return;
    }else if(ball->layer->bits[3] && !ball->layer->bits[1] && !ball->layer->bits[2]){
        //case 2
        ball->deltaY = -(ball->deltaY);
        printf("CASE 2\n");
        return;
    }else if(!ball->layer->bits[4] && !ball->layer->bits[3] && ball->layer->bits[1]){
        //case 3
        ball->deltaX = -(ball->deltaX);
        printf("CASE 3\n");
        for(int i = 0; i < 5; i++){
            printf("bit %d: %d\n",i,ball->layer->bits[i]);
        }
        return;
    }else if(ball->layer->bits[3] && ball->layer->bits[1]){
        //case 4
        ball->deltaX = -(ball->deltaX);
        ball->deltaY = -(ball->deltaY);
        printf("CASE 4\n");
        for(int i = 0; i < 5; i++){
            printf("bit %d: %d\n",i,ball->layer->bits[i]);
        }
        return;
    }
    return; 
}

void changeDeltaWithPad(BALL *ball, PAD *pad){
    if(ball->coordX >= pad->leftSide && ball->coordX< pad->center){
        printf("Left side\n");
        if(ball->deltaX == 0){
            ball->deltaX = -1;
        }else{
            ball->deltaX = -(ball->deltaX);
        }
        ball->deltaY = -(ball->deltaY);
        return;
    }else if(ball->coordX >= pad->center && ball->coordX < pad->rightside){
        printf("Center\n");
        printf("X: %d Y: %d\n",ball->coordX,ball->coordY);
        printf("LeftSide: %d\n",pad->leftSide);
        printf("Center: %d\n",pad->center);
        printf("RigthSide: %d\n",pad->rightside);
        ball->deltaY = -(ball->deltaY);
        return;
    }else if(ball->coordX >= pad->rightside && ball->coordX < ball->x + 100){
        printf("Right side\n");
        if(ball->deltaX == 0){
            ball->deltaX = 1;
        }else{
            ball->deltaX = -(ball->deltaX);
        }
        ball->deltaY = -(ball->deltaY);
        return;
    }

    return;
}
