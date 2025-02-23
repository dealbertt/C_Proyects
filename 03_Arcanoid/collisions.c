#include "header/collisions.h"
#include "header/graphics.h"
#include "header/logic.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <complex.h>

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
    assingCheckers(ball,window,pad);
    return false;
}

int assingCheckers(BALL *ball,SDL_Window *window, PAD *pad){
    bool collisionVertical = collisionPanel(window, ball, 1);
    bool collisionLateral = collisionPanel(window, ball, 0);
    if((collisionVertical = collisionPanel(window, ball, 1))|| (collisionLateral = collisionPanel(window, ball, 1))){
        changeDelta(ball,collisionVertical,collisionLateral); 
    }
    return 0;
}

bool collisionPanel(SDL_Window *window, BALL *ball, int option){
    int array[5] = {0};
    if(option == 0){
        if(ball->deltaX > 0){
            printf("Checking right side of the ball\n");
            //going to the right
            array[4] = getColorData(window, ball, ball->coordX + CHECK_SIZE, ball->y, CHECK_SIZE, CHECK_SIZE);
            array[3] = getColorData(window, ball, ball->coordX + CHECK_SIZE, ball->y + CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            array[2] = getColorData(window, ball, ball->coordX + CHECK_SIZE, ball->y + (CHECK_SIZE * 2), CHECK_SIZE,CHECK_SIZE);
            array[1] = getColorData(window, ball, ball->coordX + CHECK_SIZE, ball->y + (CHECK_SIZE * 3), CHECK_SIZE,CHECK_SIZE);
            array[0] = getColorData(window, ball, ball->coordX + CHECK_SIZE, ball->y + (CHECK_SIZE  * 4), CHECK_SIZE,CHECK_SIZE);
            for(int i = 0; i < 5; i++){
                if(array[i] == 1){
                    return true;
                }
            }
            //checks for colllisions i guess
        }else if(ball->deltaX < 0){
            //moving to the left
            printf("Checking left side of the ball\n");
            array[4] = getColorData(window, ball, ball->coordX - CHECK_SIZE, ball->y, CHECK_SIZE, CHECK_SIZE);
            array[3] = getColorData(window, ball, ball->coordX - CHECK_SIZE, ball->y + CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            array[2] = getColorData(window, ball, ball->coordX - CHECK_SIZE, ball->y + (CHECK_SIZE * 2), CHECK_SIZE,CHECK_SIZE);
            array[1] = getColorData(window, ball, ball->coordX - CHECK_SIZE, ball->y + (CHECK_SIZE * 3), CHECK_SIZE,CHECK_SIZE);
            array[0] = getColorData(window, ball, ball->coordX - CHECK_SIZE, ball->y + (CHECK_SIZE * 4), CHECK_SIZE,CHECK_SIZE);
            //checks for colllisions i guess
            for(int i = 0; i < 5; i++){
                if(array[i] == 1){
                    return true;
                }
            }
        }
    }else{
        if(ball->deltaY > 0){
            //moving up
            array[4] = getColorData(window, ball, ball->x, ball->y - 10, CHECK_SIZE, CHECK_SIZE);
            array[3] = getColorData(window, ball, ball->x + CHECK_SIZE, ball->y - 10, CHECK_SIZE,CHECK_SIZE);
            array[2] = getColorData(window, ball, ball->x + (CHECK_SIZE * 2), ball->y - 10, CHECK_SIZE,CHECK_SIZE);
            array[1] = getColorData(window, ball, ball->x + (CHECK_SIZE * 3), ball->y - 10, CHECK_SIZE,CHECK_SIZE);
            array[0] = getColorData(window, ball, ball->x + (CHECK_SIZE * 4), ball->y - 10, CHECK_SIZE,CHECK_SIZE);
            //checks for colllisions i guess
            for(int i = 0; i < 5; i++){
                if(array[i] == 1){
                    printf("Valor del array %d: %d\n", i, array[i]);
                    return true;
                }
            }
        }else if(ball->deltaY < 0){
            //moving down
            printf("Checking lower side of the ball\n");
            array[4] = getColorData(window, ball, ball->x, ball->coordY - CHECK_SIZE, CHECK_SIZE, CHECK_SIZE);
            array[3] = getColorData(window, ball, ball->x + CHECK_SIZE, ball->coordY - CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            array[2] = getColorData(window, ball, ball->x + (CHECK_SIZE * 2), ball->coordY - CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            array[1] = getColorData(window, ball, ball->x + (CHECK_SIZE * 3), ball->coordY - CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            array[0] = getColorData(window, ball, ball->x + (CHECK_SIZE * 4), ball->coordY - CHECK_SIZE, CHECK_SIZE,CHECK_SIZE);
            //checks for colllisions i guess
            for(int i = 0; i < 5; i++){
                if(array[i] == 1){
                    return true;
                }
            }
        } 
    }
    for(int i = 0; i < 5; i++){
        if(array[i] == 1){
            return true;
        }
    }
    return false;
}

int getColorData(SDL_Window *window, BALL *ball, int startX, int startY,int width,int height){
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    Uint8 color = 0;
    if(surface == NULL){
        printf("Error trying to get the surface from window");
        return -1;
    }
    SDL_LockSurface(surface);
    for(int y = startY; y < startY + height; y++){
        for (int x = startX; x < startX + width; ++x) {
            // Make sure the coordinates are within the surface bounds
            if (x >= 0 && x < surface->w && y >= 0) {
                // Get the pixel value
                Uint32 pixel = ((Uint32*)surface->pixels)[y * surface->w + x];

                // Extract the RGBA values
                Uint8 r, g, b, a;
                SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);

                // Output the color of the pixel
                if(r != 0 | g != 0 | b != 0){
                    //printf("R=%d, G=%d, B=%d, A=%d\n", r, g, b, a);
                    SDL_UnlockSurface(surface);
                    return 1;
                }
            }
        }
    }
    SDL_UnlockSurface(surface);

    return 0;
}

void changeDelta(BALL *ball,bool vertical, bool horizontal){
    printf("Changing deltas...\n");
     if(!vertical && !horizontal){
        //case 0
        //no collision;
        return;
    }else if(vertical && horizontal){
        //case 1
        printf("CASE 1\n");
        ball->deltaX = -(ball->deltaX);
        ball->deltaY = -(ball->deltaY);
        return;
    }else if(vertical && !horizontal){
        //case 2
        printf("CASE 2\n");
        printf("Old deltas - deltaX: %d, deltaY: %d\n", ball->deltaX, ball->deltaY);
        ball->deltaY = -(ball->deltaY);
        printf("New deltas - deltaX: %d, deltaY: %d\n", ball->deltaX, ball->deltaY);
        SDL_Delay(500);
        return;
    }else if(!vertical && horizontal){
        //case 3
        printf("CASE 3\n");
        ball->deltaX = -(ball->deltaX);
        return;
    }else if(vertical && horizontal){
        //case 4
        printf("CASE 4\n");
        ball->deltaX = -(ball->deltaX);
        ball->deltaY = -(ball->deltaY);
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
