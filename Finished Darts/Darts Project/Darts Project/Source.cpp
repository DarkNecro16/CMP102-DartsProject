#include "Player.h"
#include "DartBoard.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    //dartboard object created so can be passed into the player objects.
    DartBoard board;

    // the parameters set in the player objects are only defaults and will be set by the user upon input
    Player player1("default", board, 0);
    Player player2("default", board, 0);

    // game object created to call the startGame function where the user will choose success rate, name of each player, who goes first and the number of rounds to be played
    Game game(player1, player2);

    // Call the play function to start the game
    game.startGame();

}
