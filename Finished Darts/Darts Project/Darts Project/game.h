#pragma once
#include "Player.h"


// private member variables for game class 
class Game {
private:
    Player players[2];
    Player* current_player;
    int round;
    int player1_championship_wins;
    int player2_championship_wins;
    int player1setwins;
    int player2setwins;
    int player1wins;
    int player2wins;
    int player1winsfreq[7] = { 0 };
    int player2winsfreq[7] = { 0 };
    int winindarts[21] = { 0 };
    double numgames;





    // geters and setters for private member variables for game class
    // Game function passes in 2 players objects so they can play the game 
    // 301 simulates the 301 game, 501 simulates the 501 again 

public:
    Game(Player p1, Player p2);
    void play301(double numgames);
    void play501(int numgames);
    int getTurn();
    double getNumGames();
    int getPlayer1champWins();
    int getPlayer2champWins();
    int getSetsWonPlayer1();
    int getSetsWonPlayer2();
    void setNumGames(double games);
    void startGame();
    void Reset();
    void CTBstart();




};

