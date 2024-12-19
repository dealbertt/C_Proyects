#include <stdio.h>
#include <stdlib.h>

#define NEW_NAME "new_image.ppm"

int main(){
    FILE *ptr;
    ptr = fopen("image.ppm","r+");
    if(ptr == NULL){
        printf("Error while opening the file\n");
        return 1;
    }else{
        printf("File/Image opened successfully\n");
    }
    char header[3];
    fscanf(ptr,"%s\n",header);
    int width,height,max_color;
    fscanf(ptr,"%d %d %d",&width,&height,&max_color);
    int new_width, new_heigth;

    printf("The current size of the image is %d x %d\n",width,height);
    printf("please input the new desired width of the image:\n");
    scanf("%d",&new_width);
    printf("please input the new desired height of the image:\n");
    scanf("%d",&new_heigth);
    int pixels[height][width][3];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < 3; k++){
                fscanf(ptr,"%d",&pixels[i][j][k]);
                pixels[i][j][k] = pixels[i][j][k]/2;     
            }
        }
    }
    fclose(ptr);
    ptr = fopen(NEW_NAME,"w");
    if(ptr == NULL){
        printf("Error while creating the new file\n");
        return 1;
    }else{
        printf("File/Image created successfully\n");
    }
    fprintf(ptr,"%s\n",header);
    fprintf(ptr,"%d %d %d\n",width,height,max_color);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < 3; k++){
                if(k == 2 && j != width - 1){
                    fprintf(ptr,"%d    ",pixels[i][j][k]);
                }else if(k == 2 && j == width - 1){
                    fprintf(ptr,"%d\n",pixels[i][j][k]);
                }else{
                    fprintf(ptr,"%d ",pixels[i][j][k]);
                }
           }
        }
    }
    fclose(ptr);
    return 0;
}
