#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IMAGE_NAME "test.ppm"

//we first work with an array of pixels  that hold the value of the gray scale(not colors yet)
int main(){
    FILE *ptr = fopen("image.ppm","r");    
    if (ptr == NULL){
        printf("Error while opening the file\n");
        return -1;
    }else{
        printf("File opened succesfully\n");
    }
    char header[3];//The header contains the metadata such as height and width of the image
    int width,height,max_color;
    fscanf(ptr,"%s",header);
    printf("header: %s \n",header);
    fscanf(ptr, "%d\n%d\n%d",&width, &height,&max_color);
    printf("%d\n%d\n%d\n",width, height,max_color);
    if(header[0] != 'P' || header[1] != '3'){
        printf("Invalid file format\n");
        return 1;
    }
    int pixels[height][width][3];
    for(int i = 0;i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < 3; k++){
                fscanf(ptr, "%d",&pixels[i][j][k]);
                printf("%d\n",pixels[i][j][k]);
            }
        }
    }

    return 0;
}

