#include "header/game.hpp"

Game::Game(Pad &player1, Pad &player2, Ball &ball) : player1(player1), player2(player2), ball(ball){
    goalsPlayer1 = 0;
    goalsPlayer2 = 0;
}

void Game::updateScore(){
    if(ball.xPos == 20){
        goalsPlayer2++;
    }else if(ball.xPos == 1000){
        goalsPlayer1++;
    }

}
