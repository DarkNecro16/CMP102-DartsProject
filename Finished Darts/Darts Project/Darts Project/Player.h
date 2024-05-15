#pragma once
#include <string>
#include "DartBoard.h"

using namespace std;

// member variables for player class
class Player {
private:
    string name;
    int score;
    int darts_thrown;
    DartBoard board;
    int success_rate;
    int bulls_hit;
    int total_wins;
    double player1_winrate;
    double player2_winrate;
    int dartsfreq;


    // getters and setters for member variables 
    // player function passes im user inputed name and success rate and board to allow players to access board class
public:
    Player(string name, DartBoard board, int success_rate);
    string getName();
    void setName(string chosenname);
    int getDarts();
    void setDarts(int totaldarts);
    void setBullsHit(int bullshit);
    int getBullHits();
    int getSuccessRate();
    void setSuccessRate(int pickedsuccess);
    int getScore();
    void setScore(int score);
    void setWins(int totalwins);
    int getWins();
    void setPlayer1Winrate(double winratep1);
    void setPlayer2Winrate(double winratep2);
    void setDartsFreq(int freq);
    int getDartsFreq();
    double getPlayer1Winrate();
    double getPlayer2Winrate();

    // allows for players to access board class to return values from dart board 
    DartBoard& getBoard();
};

