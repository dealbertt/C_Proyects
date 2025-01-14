#include "header/utils.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

void listImages(){


    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){

        printf("Could open the directory\n");

    }
    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strstr(listedFile,".ppm")!= NULL){

            printf("%s\n",listedFile);

        }

    }
}
int isFileAvailable(char *fileName){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){

        printf("Could open the directory\n");

    }

    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strcmp(listedFile,fileName) == 0){

            printf("File is available\n");

            return 0;
        }
    }
    red();
    printf("No file with the name available\n");
    white();
    return 1;
}

int isNameTaken(char *fileName){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){
        
        printf("Could open the directory\n");

    }
    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strcmp(listedFile,fileName) == 0){

            red();
            printf("Another file with the same name already exists\n Please choose a different name\n");
            white();

            return 1;

        }
    }
    return 0;
}
void printHeader(FILE *ptr,int width,int height,int max_color){
    char header[3] = "P6";
    fprintf(ptr,"%s\n",header);
    fprintf(ptr,"%d %d %d\n",width,height,max_color);

    return; 

}
char *getFileName(){

    char *name = (char *) malloc(MAX_SIZE * sizeof(char));
    printf("Please introduce the name of the file(without .ppm at the end):");
    scanf("%s",name);

    char file_extension[4] = ".ppm";
    char *p = strstr(name,file_extension);

    if(!p){

        strcat(name,file_extension);
        printf("File name:%s",name);

    }
    if(isNameTaken(name) == 1){

        return NULL;

    }
    return name;
}


PPMImage readFile(char *fileName){
    FILE *ptr = fopen(fileName,"rb");
    if(ptr == NULL){
        printf("Unable to open the file\n");
        PPMImage image;
        return image;
    }
    int width,height,max_color;
    char header[3];
    fscanf(ptr,"%s",header);
    if(header[1] != '6'){
        printf("Unsupported file format\n");
        fclose(ptr);
        PPMImage image;
        return image;
    }
    fscanf(ptr,"%d %d %d\n",&width,&height,&max_color);
    PPMImage image;
    allocatImage(&image, width, height, max_color);
    unsigned char r,g,b;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            fread(&r,sizeof(unsigned char),1,ptr);
            fread(&g,sizeof(unsigned char),1,ptr);
            fread(&b,sizeof(unsigned char),1,ptr);

            image.pixels[i][j] = r;
            image.pixels[i][j + 1] = g;
            image.pixels[i][j + 2] = b;

        }
    } 

    fclose(ptr);
    return image;

}
int writeFile(PPMImage old_image,char *newFile){
    FILE *new_ptr = fopen(newFile,"wb");

    unsigned char r,g,b;
    printHeader(new_ptr,old_image.width,old_image.height,old_image.max_color);
    for(int i = 0; i < old_image.height; i++){
        for(int j = 0; j < old_image.width; j++){

            r = old_image.pixels[i][j];
            g = old_image.pixels[i][j + 1];
            b = old_image.pixels[i][j + 2];

            fwrite(&r,sizeof(unsigned char),1,new_ptr);
            fwrite(&g,sizeof(unsigned char),1,new_ptr);
            fwrite(&b,sizeof(unsigned char),1,new_ptr);
        }
    } 
    fclose(new_ptr);
    return 0;


}
void allocatImage(PPMImage *image, int width, int height, int maxColor){
    image->height = height;
    image->width= width;
    image->max_color = maxColor;
    

    image->pixels = malloc(height * sizeof(unsigned char *));
    for(int i = 0; i < height; i++){

            image->pixels[i] = malloc(width * sizeof(unsigned char));
    }
}
void freeImage(PPMImage *img) {
    // Free each row
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    // Free the row pointers
    free(img->pixels);
}
