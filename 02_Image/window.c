#include "header/window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>


//im thinking about drawing as many small rectangles as pixels in the image
void displayImage(PPMImage *image){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("image processor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, image->width,image->height, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    //SDL_Rect rect = {200,200,200,200};
    //SDL_FillRect(surface, &rect, 0xffffffff);
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            unsigned char r = image->pixels[i][j * 3];
            unsigned char g = image->pixels[i][j * 3 + 1];
            unsigned char b = image->pixels[i][j * 3 + 2];
            unsigned int color = rgbToHex(r, g, b);
            SDL_Rect rect = {j,i,1,1};
            SDL_FillRect(surface,&rect,color);
        }
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}


unsigned int rgbToHex(unsigned char r, unsigned char g, unsigned char b){
    unsigned char a = 255;
    unsigned int color = (a<<24) | (r << 16) | (g << 8) | b;
    return color;
}
