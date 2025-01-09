#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    int width;
    int height;
    int max_color;
    unsigned char *pixels;
}PPMImage;

PPMImage *readFile(char *fileName);
int main(int argc, char **argv){
    if(argc == 1){

        printf("Please provide an argument\n");
        return 1;

    }
    PPMImage *image = readFile(argv[1]);
    printf("Width: %d\n",image->width);
    printf("Height: %d\n",image->height);
    printf("Max color: %d\n",image->max_color);
    free(image);
    return 0;
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
    printf("Header: %s\n",header);
    printf("Values: %d %d %d\n",width,height,max_color);
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
    free(pixels);
    fclose(ptr);
    return image;

}
/*
FILE *clone = fopen("clone_image.ppm","wb");
    fprintf(clone,"P6\n");
    fprintf(clone,"%d %d %d\n",width,height,max_color);
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            int index = (j * width + i) * 3;
            unsigned char r,g,b;
            r = pixels[index];
            g = pixels[index + 1];
            b = pixels[index + 2];
            fwrite(&r,sizeof(unsigned char),1,clone);
            fwrite(&g,sizeof(unsigned char),1,clone);
            fwrite(&b,sizeof(unsigned char),1,clone);
        }
    } 


    free(pixels);
    fclose(ptr);
    fclose(clone);
*/
