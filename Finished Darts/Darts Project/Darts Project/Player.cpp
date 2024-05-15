#include "Player.h"
#include<iostream>


// constructor passes in players user inputed success rate and name and also the board so the player can throw darts at the board and return values.
Player::Player(string name, DartBoard board, int success_rate)
    : name(name), score(301), darts_thrown(0), dartsfreq(0), board(board), success_rate(success_rate), bulls_hit(0), total_wins(0), player1_winrate(0), player2_winrate(0) {}

// keeps track of players name
string Player::getName()
{
    return name;
}


// allows the players name to be chosen 
void Player::setName(string chosenname)
{
    name = chosenname;


}

// allows the current score to be updated 
int Player::getScore()
{
    return score;
}


// allows the score to be changed 
void Player::setScore(int newScore)
{
    score = newScore;
}


// allows success rate to be passed to other functions
int Player::getSuccessRate()
{
    return success_rate;
}

//allows to modify
void Player::setSuccessRate(int pickedsuccess)
{
    success_rate = pickedsuccess;
}

//allows to pull dart count for each player
int Player::getDarts()
{
    return darts_thrown;
}


// allows to increment
void Player::setDarts(int totaldarts)
{
    darts_thrown = totaldarts;
}


// too keep track of wins 
void Player::setWins(int totalwins)
{
    total_wins = totalwins;
}

// to display wins at end of game 
int Player::getWins()
{
    return total_wins;
}


// too set winrate after each game
void Player::setPlayer1Winrate(double winratep1)
{
    player1_winrate = winratep1;
}

void Player::setPlayer2Winrate(double winratep2)
{
    player2_winrate = winratep2;
}

// to allow display of winrate at end of game 
double Player::getPlayer1Winrate()
{
    return player1_winrate;
}

double Player::getPlayer2Winrate()
{
    return player2_winrate;
}



//allows access to board functions
DartBoard& Player::getBoard()

{
    return board;
}

//keeps track of bull hits 
void Player::setBullsHit(int bullshit)
{

    bulls_hit = bullshit;


}

// displays bullshit at end of game 
int Player::getBullHits()
{

    return bulls_hit;


}

void Player::setDartsFreq(int freq)

{
    dartsfreq = freq;
}

int Player::getDartsFreq()

{
    return dartsfreq;
}











