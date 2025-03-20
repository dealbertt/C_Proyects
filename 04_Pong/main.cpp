#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_hints.h>


//Headers created for the program
#include "header/pad.hpp"
#include "header/ball.hpp"
#include "header/graphics.h"
#include "header/game.hpp"

//First C++ proyect, i am planning on reading books and such to get good at it but i wanted
//to first see what i know and use Chatgpt a little bit to help me on the basics of the language


//For the "AI" players, 
//- do something where they get a snapshot of the deltas of the ball
//- Predict where the ball might be going based on that snapshot
//- Move the pad based on that prediction


//TODO: Chna
bool running = true;

Config config;

#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"
void gameLoop(SDL_Window *window, SDL_Surface *surface, Pad *player1, Pad *player2, Ball *ball, Game *game);


int initGame(SDL_Window **window, SDL_Surface **surface, Pad **player1, Pad **player2, Ball **ball, Game **game){
    config = readConfiguration("config.txt");
    
    *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.windowWidth, config.windowHeigth, 0);
    if(*window == NULL){
        perror("Error while trying to created SDL Window\n");
        return  -1;
    }

    *surface = SDL_GetWindowSurface(*window);
    if(*surface == NULL){
        perror("Error trying to create SDL_Surface\n");
        return -1;
    }

    *ball = new Ball(BALL_DEFAULT_X, BALL_DEFAULT_Y,1,0, config.ballSpeed);
    int delta = (*ball)->chooseDelta();
    (*ball)->setDeltaX(delta);  
    (*ball)->drawBall(*window, *surface, WHITE, false);
    (*ball)->Initialize();

    *player1 = new Pad(PLAYER1_DEFAULT_X, PAD_DEFAULT_Y, config.padSpeed, BRICK_WIDTH, RED);
    (*player1)->Initialize();
    (*player1)->drawPad(*window, *surface, RED);

    *player2 = new Pad(PLAYER2_DEFAULT_X, PAD_DEFAULT_Y, config.padSpeed, 0, PURPLE);
    (*player2)->Initialize();
    (*player2)->drawPad(*window, *surface, PURPLE);

    *game = new Game(**player1, **player2, **ball); 
    (*game)->timer= (TIMER*)malloc(sizeof(TIMER));
    (*game)->timer->value = config.gameSpeed;
    (*game)->timer->resetValue = config.gameSpeed;
    (*game)->timer->activated = false;
    std::cout << "Time value " << (*game)->timer->value << std::endl;
    if(*game  == NULL){
        perror("Error trying to create Game object\n");
        return -1;
    }


    return 0;
}

int main(){
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    
    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    SDL_Init(SDL_INIT_VIDEO);



    Ball *ball = nullptr;
    Pad *player1 = nullptr;
    Pad *player2 = nullptr;
    Game *game = nullptr;

    if (initGame(&window, &surface, &player1, &player2, &ball, &game) != 0) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return -1;
    }


    SDL_UpdateWindowSurface(window);
    gameLoop(window, surface, player1, player2, ball, game);
    SDL_Delay(1000);
    SDL_Quit();
    delete player1; 
    delete player2; 
    delete ball; 


    return 0;
}

void gameLoop(SDL_Window *window, SDL_Surface *surface, Pad *player1, Pad *player2, Ball *ball, Game *game){
    int values[4];
    Uint32 lastFrameTime = SDL_GetTicks();
    while(running){
        //update ball
        float deltaTime = game->updateGame(window, config, lastFrameTime);
        game->ballStatus(values);
        game->turn = ball->collisionWithPlayers(player1, player2);
        if(ball->getDeltaX() == 1){
            //the ball has just collided with player1
            //i now have to give turn to player2
            player2->playerMoves(ball->getY(), window, surface, deltaTime);
        }else if(ball->getDeltaX() == -1){
            //the ball has just collided with player2
            //i have to give turn to player1
            player1->playerMoves(ball->getY(), window, surface, deltaTime);
        }
        ball->collisionWithPlayers(player1, player2);
        ball->updateBall(window, surface, deltaTime);
        if(game->goalIsScored() == 1){
            //a goal has been scored
            game->resetGame(config, window, surface); 
        }
        //the moving actions of the players will be made inside the decision functions
        //moves players
        //check for collisions and stuff i guess
    }

    return;

}
