#include "../header/config.hpp"

Config *readConfiguration(const char *path){
    FILE *ptr = fopen(path, "r");
    if(ptr == NULL){
        perror("Error while trying to open the config file");
        exit(1);
    }
    Config *config = (Config *)malloc(sizeof(Config));
    char line[100];
    while(fgets(line, sizeof(line), ptr)){
        if(line[0] == '#' || strlen(line) < 3) continue; 
        if(strstr(line, "NUMBER_ELEMENTS")) sscanf(line, "NUMBER_ELEMENTS=%d", &config->numberElements);
        else if(strstr(line, "WINDOW_WIDTH")) sscanf(line, "WINDOW_WIDTH=%d", &config->windowWidth);
        else if(strstr(line, "WINDOW_HEIGHT")) sscanf(line, "WINDOW_HEIGHT=%d", &config->windowHeigth);
        else if(strstr(line, "FPS")) sscanf(line, "FPS=%d", &config->fps);
    }
    fclose(ptr);
    std::cout << "Number of elements: " << config->numberElements << "\n";
    std::cout << "Window Width: " << config->windowWidth << "\n";
    std::cout << "Window Height: " << config->windowHeigth << "\n";
    std::cout << "FPS: " << config->fps << "\n";

    return config;
}
