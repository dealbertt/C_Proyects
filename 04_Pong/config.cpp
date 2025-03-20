#include "header/config.hpp"

Config readConfiguration(const char *path){
    FILE *ptr = fopen(path, "r");
    if(ptr == NULL){
        perror("Error while trying to open the config file");
        exit(1);
    }
    Config config;
    char line[100];
    while(fgets(line, sizeof(line), ptr)){
        if(line[0] == '#' || strlen(line) < 3) continue; 
        if(strstr(line, "BALL_SPEED")) sscanf(line, "BALL_SPEED=%f", &config.ballSpeed);
        else if(strstr(line, "PAD_SPEED")) sscanf(line, "PAD_SPEED=%f", &config.padSpeed);
        else if(strstr(line, "GAME_TIMER")) sscanf(line, "GAME_TIMER=%d", &config.gameSpeed);
        else if(strstr(line, "WINDOW_WIDTH")) sscanf(line, "WINDOW_WIDTH=%d", &config.windowWidth);
        else if(strstr(line, "WINDOW_HEIGHT")) sscanf(line, "WINDOW_HEIGHT=%d", &config.windowHeigth);
        else if(strstr(line, "FPS")) sscanf(line, "FPS=%d", &config.fps);
    }
    fclose(ptr);
    std::cout << "Ball speed: " << config.ballSpeed << "\n";
    std::cout << "Pad speed: " << config.padSpeed << "\n";
    std::cout << "Window Width: " << config.windowWidth << "\n";
    std::cout << "Window Height: " << config.windowHeigth << "\n";

    return config;
}
