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
        if(strstr(line, "BALL_TIMER")) sscanf(line,"BALL_TIMER=%hu", &config.ballTimer);
        else if(strstr(line, "PAD_TIMER")) sscanf(line, "PAD_TIMER=%hu", &config.padTimer);
    }
    fclose(ptr);
    std::cout << "Ball timer: " << config.ballTimer << "\n";
    std::cout << "Pad timer: " << config.padTimer<< "\n";

    return config;
}
