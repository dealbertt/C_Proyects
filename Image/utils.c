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


PPMImage *readFile(char *fileName){
    FILE *ptr = fopen(fileName,"rb");
    if(ptr == NULL){
        printf("Unable to open the file\n");
        return NULL;
    }
    int width,height,max_color;
    char header[3];
    fscanf(ptr,"%s",header);
    if(header[1] != '6'){
        printf("Unsupported file format\n");
        fclose(ptr);
        return NULL;
    }
    fscanf(ptr,"%d %d %d\n",&width,&height,&max_color);
    unsigned char *pixels = (unsigned char *) malloc(3 * width * height);
    unsigned char r,g,b;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            fread(&r,sizeof(unsigned char),1,ptr);
            fread(&g,sizeof(unsigned char),1,ptr);
            fread(&b,sizeof(unsigned char),1,ptr);

            int index = (j * width + i) * 3;
            pixels[index] = r;
            pixels[index + 1] = g;
            pixels[index + 2] = b;

        }
    } 

    PPMImage *image = (PPMImage *)malloc(sizeof(PPMImage)) ;
    image->height = height;
    image->width= width;
    image->max_color= max_color;
    image->pixels = pixels;
    fclose(ptr);
    return image;

}
int writeFile(PPMImage *old_image,char *newFile){
    FILE *new_ptr = fopen(newFile,"wb");

    unsigned char r,g,b;
    printHeader(new_ptr,old_image->width,old_image->height,old_image->max_color);
    for(int i = 0; i < old_image->width; i++){
        for(int j = 0; j < old_image->height; j++){
            int index = (j * old_image->width + i) * 3;

            r = old_image->pixels[index];
            g = old_image->pixels[index + 1];
            b = old_image->pixels[index + 2];

            fwrite(&r,sizeof(unsigned char),1,new_ptr);
            fwrite(&g,sizeof(unsigned char),1,new_ptr);
            fwrite(&b,sizeof(unsigned char),1,new_ptr);
        }
    } 
    fclose(new_ptr);
    return 0;


}
