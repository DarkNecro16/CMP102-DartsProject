#include "Game.h"
#include "player.h"
#include "dartBoard.h"
#include <iostream>
#include <iomanip>

using namespace std;


// constructer to create a game. initializes array with 2 player objects passed as arguments which values will be amended in main cpp
//the 2 players are put into an array and current_player points to the starting player and is used to keep track of the current player.
// the round variable initialises the game at round 1 this variable can also be used to start and end game and get round based statistics 

Game::Game(Player player1, Player player2)
    : players{ player1, player2 }, current_player(&players[0]), round(1), numgames(0), player1_championship_wins(0), player2_championship_wins(0),
    player1setwins(0), player2setwins(0), player1wins(0), player2wins(0) {}


// this game function will run until the current_players score of 301 reaches zero
// displays name of current player and what round it is 

void Game::play301(double numgames)
{



    for (int i = 0; i < numgames; i++)
    {


        while (current_player->getScore() != 0)
        {

            // the score variable gets the score for each player (301) from the player class and brings it into this one
            // the new score is needed to update the score from the old one to the new one once the dart has been thrown.


            int score = current_player->getScore();
            int success_rate = current_player->getSuccessRate();
            int bulls_hit = current_player->getBullHits();
            int total_wins = current_player->getWins();
            int new_score = 0;
            int totalDarts = 0;

            int throw_result = 0;


            // Print the round and current player
            cout << "------------------------" << endl;
            cout << "         ROUND " << round << endl;
            cout << "------------------------" << endl;
            cout << endl;
            cout << "Current player: " << current_player->getName() << endl;
            cout << endl;


            // this is where the logic is. if the player score is above 100 then the player will always aim for the bull 
            //this is based on the players accuracy rate which is set when creating the player object there is also a 10%
            // chance that either side of the targeted segment can be hit. the score variable is used to hold the players score from the player class
           //at the beggining of each round its compared to the score held and targets which segment needed accordingly.
            if (score > 100)
            {

                throw_result = current_player->getBoard().throw_bull(success_rate);



            }


            // if the score gets between 99 and 70 then the player will aim for the 20 segment
            // still with a chance of hitting another number 

            else if (score >= 70)
            {
                throw_result = current_player->getBoard().throw_single(success_rate, 20);

            }

            else if (score > 50)
            {
                // Aim for segment that will get score down to 50
                throw_result = current_player->getBoard().throw_single(success_rate, (score - 50));



            }
            // if score gets to exactly 50 then player will throw bull to end game
            else if (score == 50)
            {

                throw_result = current_player->getBoard().throw_bull(success_rate);


            }

            if (throw_result == 50)

            {
                current_player->setBullsHit(bulls_hit + 1);
            }



            //updates dart throw count in player class every time dart is thrown 

            int darts_thrown = current_player->getDarts();
            int darts_freq = current_player->getDartsFreq();
            current_player->setDarts(darts_thrown + 1);
            current_player->setDartsFreq(darts_freq + 1);


            // creates a variable for the players current score by getting there score and deducting the throw result 

            new_score = current_player->getScore() - throw_result;


            // Check if the dart the current player will throw will take them  below 50 before reaching the score of exactly 50 
            // if it does it will skip a turn and switch the player while not executing this code again and moving onto the next 
            // iteration of the loop.
            if (new_score < 50 && new_score != 0)
            {

                cout << "Score below 50, Changing player " << endl;
                if (current_player == &players[0])
                {
                    current_player = &players[1];
                }
                else
                {
                    current_player = &players[0];
                }
                round++;
                continue;
            }

            // Output score after every dart
            cout << current_player->getName() << " scored " << throw_result << " points there New score is: " << new_score << endl;

            // Update player score
            current_player->setScore(new_score);

            // Check if game is over
            if (new_score == 0)
            {

                // this variable will be put into the winfreq array to show winfreq
                totalDarts = current_player->getDartsFreq();

                // turn winrate into a %
                double winratep1 = (players[0].getWins()) * 1000 / numgames;
                double winratep2 = (players[1].getWins()) * 1000 / numgames;


                cout << "" << endl;
                cout << current_player->getName() << " wins the game congratulations!! " << endl;
                cout << "" << endl;
                // sets the total wins for each player & also stores the amount of darts it took to finish round in the winindarts array to print freq
                current_player->setWins(total_wins + 1);
                winindarts[totalDarts]++;
                cout << "" << endl;
                cout << " the round was won in: " << current_player->getDartsFreq() << " darts " << endl;
                cout << "" << endl;

                // this will set the winrate for each player
                players[0].setPlayer1Winrate(winratep1);
                players[1].setPlayer2Winrate(winratep2);

                Reset(); // resets stats back to original 

                // Switches to other player at the end of the game so each player gets a chance to start 
                if (current_player == &players[0])
                {
                    current_player = &players[1];
                }
                else
                {
                    current_player = &players[0];
                }



                break;
            }





            // Switches to other player at the end of turn
            if (current_player == &players[0])
            {
                current_player = &players[1];
            }
            else
            {
                current_player = &players[0];
            }
            round++;

        }
    }


}

void Game::play501(int numgames)


{

    // these will be used to reset the set and game counters so multipile championships can be played 
    int player1_game_wins = 0;
    int player2_game_wins = 0;
    int player1_set_wins = 0;
    int player2_set_wins = 0;


    // this loop controls the amount of games the user chooses 
    for (int j = 0; j < numgames; j++)


    {

        
        
            // this will play closest to the bull to determine who starts 
            CTBstart();

        

        // this loop controls the amount of sets in a championship 
        for (int championship = 0; championship < 13; championship++)

        {




            // this controls the amount of games needed to win a set 
            for (int game = 0; game < 5; game++)
            {


                // sets the players score and round  to 501 at the start of every game 
                players[0].setScore(501);
                players[1].setScore(501);
                round = 1;



                // this while loop contains the throw logic and will run until a player reaches a score of 0
                while (current_player->getScore() != 0)
                {


                    cout << "------------------------" << endl;
                    cout << "         TURN " << round << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Current player: " << current_player->getName() << endl;
                    cout << endl;



                    // keeps track of score at the end of every turn if the players score goes below 1 or is equal to 1 the score will revert back to this 
                    int original_score = current_player->getScore();


                    // this contains the main throw logic and will run 3 times for each player, simulating 3 dart throws 
                    for (int darts = 0; darts < 3; darts++)
                    {

                        // Get the current player's score and success rate and pull in bulls hit to increment
                        int score = current_player->getScore();
                        int success_rate = current_player->getSuccessRate();
                        int bulls_hit = current_player->getBullHits();


                        // the variable to pull in the segment hit on the board 
                        int throw_result = 0;



                        // if score reaches 50 player will throw a bull to end game, if score is 100 player will aim for a bull to finish on a bull on there next dart 
                        if (score == 50)
                        {
                            throw_result = current_player->getBoard().throw_bull501(success_rate);
                            current_player->setBullsHit(bulls_hit + 1);
                        }




                        // if score is less than or equal to 40 the player will throw a double of there current score so if score was 38 they would throw 38,
                        // however the division by 2 will make the player throw a double 19
                        // if the score is an uneven number then player will throw a 1 to bring it to an even number 
                        else if (score <= 40)
                        {
                            if (score % 2 == 1)
                            {
                                throw_result = current_player->getBoard().throw_single501(success_rate, 1);
                            }
                            else
                            {
                                throw_result = current_player->getBoard().throw_double(success_rate, score / 2);
                            }
                        }


                        // if score is less than 50 player will throw a single to get score to 40 so if score is 48 player will throw an 8
                        else if (score < 50)
                        {
                            throw_result = current_player->getBoard().throw_single501(success_rate, (score - 40));
                        }

                        // if the score is equal to or less than 70 player will throw a single to get score to 50 
                        else if (score <= 70 && score > 50)
                        {
                            throw_result = current_player->getBoard().throw_single501(success_rate, (score - 50));
                        }

                        // if the players score is less than 90 and greater than 70 the player will throw a treble 20 bringinig them in range to the score of 40 
                        // allowing them to finish on a double on there next dart 
                        else if (score < 90 && score > 70)


                        {
                            throw_result = current_player->getBoard().throw_treble(success_rate, 20);
                        }


                        // if the score is greater than 100 the player will attempt to keep there score even by throwing a treble 19 if score is odd
                        // or throw a treble 20 if score is even this will allow player to keep score even for a double finish 
                        else
                        {
                            if (score > 100 && score % 2 == 0)
                            {
                                throw_result = current_player->getBoard().throw_treble(success_rate, 20);
                            }
                            else
                            {
                                throw_result = current_player->getBoard().throw_treble(success_rate, 19);
                            }
                        }


                        // this takes the players dart throw value off there total score and sets it
                        score -= throw_result;
                        current_player->setScore(score);

                        // increments the darts thrown for each player 
                        int darts_thrown = current_player->getDarts();
                        current_player->setDarts(darts_thrown + 1);

                        // this will print the throw value and the new score of the player 

                        cout << " Dart  " << darts + 1 << " Total: " << throw_result << endl;
                        cout << " " << endl;
                        cout << "New Score is: " << score << endl;
                        cout << " " << endl;



                        // this checks to see if the player finished on a double and when there score reaches 0 will increment there game wins
                        // please note the local variable increments but will reset when the player wins the set so theres an additional member
                        // to keep track of how many game wins the player has
                        if (current_player->getScore() == 0 && throw_result % 2 == 0)
                        {
                            cout << current_player->getName() << " wins the game" << endl;

                            if (current_player == &players[0])
                            {
                                player1_game_wins++;
                                player1wins++;
                                break;
                            }
                            else
                            {
                                player2_game_wins++;
                                player2wins++;
                                break;
                            }

                        }




                        // this checks to see if a players score reaches 1 or below 0 if so the player is bust 
                        // and all darts of that turn will be discounted and the score will revert back to what it was at the end of there last turn
                        if (current_player->getScore() < 0 || current_player->getScore() == 1)
                        {
                            cout << "Player must finish on a double, score reverted to end of last turn." << endl;

                            // Set the score to the original score before the throw
                            current_player->setScore(original_score);

                            break;
                        }


                        // when the player has thrown 3 darts player switches 
                        if (darts == 2)
                        {
                            if (current_player == &players[0])
                            {
                                current_player = &players[1];
                            }
                            else
                            {
                                current_player = &players[0];
                            }
                        }


                    }



                    // this will allow for each player to have a turn at starting the new game 
                    if (players[0].getScore() == 0 || players[1].getScore() == 0)
                    {


                        if (current_player == &players[0])
                        {
                            current_player = &players[1];
                        }
                        else
                        {
                            current_player = &players[0];
                        }

                        break;
                    }
                    round++;
                }


                // if a player wins 3 games then they will win the set just like before there are local variables as these will be reset to allow multiple championships
                // the member variable is too keep track of sets won 
                // the game_ wins will reset here to allow multiple sets to be played to complete championship 
                if (player1_game_wins == 3)
                {


                    cout << players[0].getName() << " wins the set!" << endl;

                    player1_set_wins++;
                    player1_game_wins = 0;
                    player2_game_wins = 0;
                    player1setwins++;

                    break;

                }

                else if (player2_game_wins == 3)
                {



                    cout << players[1].getName() << " wins the set!" << endl;

                    player2_set_wins++;
                    player1_game_wins = 0;
                    player2_game_wins = 0;
                    player2setwins++;





                    break;


                }






            }

            // the same as before if a player wins 7 of the 13 sets then they win the championship 
            //the set wins are reset to allow multiple championship simulation
            // the win freq array will record how many sets each player had won at the time the champpionship ends
            if (player1_set_wins == 7)
            {
                cout << players[0].getName() << " has won the championship! " << endl;
                player1winsfreq[player1_set_wins, player2_set_wins]++;
                player1_championship_wins++;
                player1_set_wins = 0;
                player2_set_wins = 0;



                break;
            }

            else if (player2_set_wins == 7)
            {
                cout << players[1].getName() << " has won the championship! " << endl;
                player2winsfreq[player2_set_wins, player1_set_wins]++;
                player2_championship_wins++;
                player1_set_wins = 0;
                player2_set_wins = 0;


                break;

            }




        }

    }





}

void Game::CTBstart()
{


    // variables for closest to bull
    int success_ratebull = current_player->getSuccessRate();
    int throw_resultbullp1 = players[0].getBoard().ClosestToBull(success_ratebull);
    int throw_resultbullp2 = players[1].getBoard().ClosestToBull(success_ratebull);

    // first player is a local as its just used to determine who will throw first, the next player uses a pointer to update the nextplayer variable to the person who will throw next 

    int first_player = 0;
    Player* next_player;



    cout << players[0].getName() << " has threw a " << throw_resultbullp1 << endl;
    cout << players[1].getName() << " has threw a " << throw_resultbullp2 << endl;


    // if player 1 gets closer than player 2 then they will start, otherwise player 2 will start.

    if (throw_resultbullp1 > throw_resultbullp2)
    {
        first_player = 0;

        current_player = &players[0];

        next_player = &players[1];
    }
    else
    {
        first_player = 1;

        current_player = &players[1];

        next_player = &players[0];
    }

    // if they draw then it will throw again until there is a winner 

    if (throw_resultbullp1 == throw_resultbullp2)
    {
        CTBstart();
    }
}


// this function is called and will allow the player to choose the players name and success rate aswell who starts for 301 and how many championships will be played in 501
void Game::startGame()
{


    int choice = 0;

    cout << " Welcome To Davids Dynamite Championsip Darts " << endl;
    cout << "" << endl;
    cout << " what game would you like to play 301 darts or 501? " << endl;
    cout << "" << endl;
    cout << " please press 1 for 301 or 2 for 501 " << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1)

    {
        // brings in a board object to allow the creation of a player object as each player needs a board to play
        DartBoard board1;
        DartBoard board2;

        string name1, name2;
        int success_rate1, success_rate2;
        int numgames = 0;

        // this will allow for the players success rates to be input
        cout << " Please enter the first players name: " << endl;
        cin >> name1;
        cout << "Please enter the second players success rate (0-100): " << endl;
        cin >> success_rate1;
        cin.ignore(); // ignore the newline character left in the input from the previous cin entry from user 


        cout << " Please enter the second players name: " << endl;
        cin >> name2;
        cout << " Please enter the second players success rate (0-100): " << endl;
        cin >> success_rate2;
        cin.ignore();

        // Create player objects and ubdates the players array
        players[0] = Player(name1, board1, success_rate1);
        players[1] = Player(name2, board2, success_rate2);

        // this determines who goes first in 301, first player is local and sets the starting player and then we point to the player object to allow the other player to go
        cout << "Which player would you like to go first?  (Enter 1 for " << players[0].getName() << " or 2 for " << players[1].getName() << "): " << endl;
        int first_player_choice;

        Player* next_player;

        cin >> first_player_choice;
        cin.ignore();

        // Set current player to the chosen player
        if (first_player_choice == 1)
        {
            current_player = &players[0];

            next_player = &players[1];
        }
        else
        {
            current_player = &players[1];

            next_player = &players[0];
        }


        // allows the user to select how many games they want to play 
        cout << " Please enter the number of games you would like to play : " << endl;
        cin >> numgames;



        play301(numgames);

        // when all games are finished prints out match statistics 
        if (numgames > 0)
        {



            cout << "" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Statistics for " << numgames << " games played:" << endl;
            cout << "-----------------------------------------" << endl;
            cout << players[0].getName() << "has won " << players[0].getWins() << " games" << endl;
            cout << players[1].getName() << "has won " << players[1].getWins() << " games" << endl;
            cout << "" << endl;
            cout << players[0].getName() << " hit the bullseye " << players[0].getBullHits() << " times" << endl;
            cout << players[1].getName() << " hit the bullseye " << players[1].getBullHits() << " times" << endl;
            cout << "" << endl;
            cout << players[0].getName() << " threw " << players[0].getDarts() << " darts" << endl;
            cout << players[1].getName() << " threw " << players[1].getDarts() << " darts" << endl;
            cout << "" << endl;

            if (numgames < 100)
            {
                cout << " the win rate % for " << players[0].getName() << " is: " << setprecision(3) << players[0].getWins() * 100 / numgames << " % " << endl;
                cout << "" << endl;
                cout << " the win rate % for " << players[1].getName() << " is: " << setprecision(3) << players[1].getWins() * 100 / numgames << " % " << endl;
                cout << "" << endl;
            }
            else if (numgames > 100)
            {
                cout << " the win rate % for " << players[0].getName() << " is: " << setprecision(3) << players[0].getPlayer1Winrate() / 10 << " % " << endl;
                cout << "" << endl;
                cout << " the win rate % for " << players[1].getName() << " is: " << setprecision(3) << players[1].getPlayer2Winrate() / 10 << " % " << endl;
                cout << "" << endl;

            }

            cout << "Games finished in:" << endl;
            cout << " " << endl;
            cout << " ----------------------------------------- " << endl;

            cout << setw(10) << left << "Darts" << setw(10) << left << "Wins" << setw(15) << left << "Frequency (%)" << endl;
            cout << " " << endl;
            cout << " ----------------------------------------- " << endl;

            // prints out how many games finished in X amount of darts the setw function allows us to space out columbs for easier reading 
            // the for loop itirates through each element of stored dart finishes from when the players score reaches 0 block of code 
            for (int i = 7; i <= 20; i++)

            {
                double frequenices = winindarts[i] * 1000 / numgames;


                cout << setw(10) << left << i << setw(10) << left << winindarts[i] << setw(1) << setprecision(3) << frequenices / 10 << " % " << endl;
            }

            system("pause");


        }

    }

    if (choice == 2)

    {

        DartBoard board1;
        DartBoard board2;

        string name1, name2;
        int success_rate1, success_rate2;
        int numgames = 0;


        // this will allow for the players success rates to be input
        cout << " Please enter the first players name: " << endl;
        cin >> name1;
        cout << "Please enter the second players success rate (0-100): " << endl;
        cin >> success_rate1;
        cin.ignore();


        cout << " Please enter the second players name: " << endl;
        cin >> name2;
        cout << " Please enter the second players success rate (0-100): " << endl;
        cin >> success_rate2;
        cin.ignore();

        // Create player objects
        players[0] = Player(name1, board1, success_rate1);
        players[1] = Player(name2, board2, success_rate2);

        cout << " Please enter the number of games you would like to play : " << endl;
        cin >> numgames;



        // will run 501 monte carlo simulation 
        play501(numgames);


        // when games reaches 0 it will display the match statistics 
        if (numgames > 0)
        {
            cout << "" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Statistics for " << numgames << " games played:" << endl;
            cout << "-----------------------------------------" << endl;
            cout << players[0].getName() << "has won " << player1wins << " games" << endl;
            cout << players[1].getName() << "has won " << player2wins << " games" << endl;
            cout << "" << endl;
            cout << players[0].getName() << " threw " << players[0].getDarts() << " darts" << endl;
            cout << players[1].getName() << " threw " << players[1].getDarts() << " darts" << endl;
            cout << "" << endl;
            cout << players[0].getName() << " hit the bullseye " << players[0].getBullHits() << " times" << endl;
            cout << players[1].getName() << " hit the bullseye " << players[1].getBullHits() << " times" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << players[0].getName() << " has won " << getPlayer1champWins() << " championships " << endl;
            cout << "" << endl;
            cout << players[1].getName() << " has won " << getPlayer2champWins() << " championships " << endl;
            cout << "" << endl;
            cout << players[0].getName() << " has won " << getSetsWonPlayer1() << " sets " << endl;
            cout << "" << endl;
            cout << players[1].getName() << " has won " << getSetsWonPlayer2() << " sets " << endl;
            cout << "" << endl;

            cout << "" << endl;
            cout << players[0].getName() << "s" << " win frequency results " << endl;
            cout << "" << endl;



            // displays player 1s win frequencies itirates 7 times so each result can be printed 
            // pulls in player1_set_wins which is == i and siaplays percentage 
            for (int i = 0; i < 7; i++)
            {

                float player1_percentage = (float)player1winsfreq[i] / numgames * 100;



                cout << players[0].getName() << " finished  " << player1winsfreq[i] << " championships (" << player1_percentage << "%) with score " << 7 << ":" << i << endl;

            }

            cout << "" << endl;
            cout << players[1].getName() << "s" << " win frequency results " << endl;
            cout << "" << endl;

            // displays player 2s win frequencies itirates 7 times so each result can be printed 
            // pulls in player2_set_wins which is == m and siaplays percentage 
            for (int m = 0; m < 7; m++)
            {
                float player2_percentage = (float)player2winsfreq[m] / numgames * 100;


                cout << players[1].getName() << " finshed " << player2winsfreq[m] << " championships (" << player2_percentage << "%) with score " << 7 << ":" << m << endl;
            }

            system("PAUSE");


        }

    }
}



// gets player championships wins 
int Game::getPlayer1champWins()
{
    return player1_championship_wins;
}
int Game::getPlayer2champWins()
{
    return player2_championship_wins;
}


int Game::getTurn()
{

    return round;
}

// gets player set wins 
int Game::getSetsWonPlayer1()

{
    return player1setwins;
}

int Game::getSetsWonPlayer2()

{
    return player2setwins;
}






// resets score and dart values for 301 darts needs reset to keep track of win freq
void Game::Reset()
{
    players[0].setScore(301);
    players[1].setScore(301);
    players[0].setDartsFreq(0);
    players[1].setDartsFreq(0);
    round = 1;

}

void Game::setNumGames(double games)
{
    games = numgames;
}

double Game::getNumGames()
{

    return numgames;
}





















