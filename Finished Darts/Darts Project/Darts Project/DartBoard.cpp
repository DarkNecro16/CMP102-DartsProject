#include "DartBoard.h"
#include <cstdlib>
#include <iostream>


using namespace std;



// throw single passes in throw variable from game and depending on player success rate will hit target or segment to left or right with equal 5% chance otherwise will
// return random segment between 1 and 20
int DartBoard::throw_single(int successrate, int dartval)
{

	int darthit = 0;

	int random = rand() % 100 + 1;

	successrate = 80;



	if (random < successrate)

	{
		cout << " dart hit " << dartval << endl;


		return dartval;

	}

	else if (random < successrate + 10)

	{

		cout << "dart missed and hit " << bd[0][dartval] << endl;


		return bd[0][dartval];


	}


	else if (random < successrate + 20)
	{


		cout << "dart missed and hit " << bd[1][dartval] << endl;


		return bd[1][dartval];
	}

	else
	{
		darthit = 1 + rand() % 20;

		cout << "dart hit " << darthit << endl;

		return darthit;
	}

}


// takes the hard coded success rate and also adds the possibilty the player can hit the wall 
int DartBoard::throw_single501(int successrate, int dartval)

{

	int darthit = 0;
	int random = rand() % 100 + 1;





	if (random < successrate)

	{
		cout << " dart hit " << dartval << endl;


		return dartval;

	}

	else if (random < successrate + 5)

	{

		cout << "dart missed and hit " << bd[0][dartval] << endl;


		return bd[0][dartval];


	}


	else if (random < successrate + 10)
	{


		cout << "dart missed and hit " << bd[1][dartval] << endl;


		return bd[1][dartval];
	}

	else if (random < successrate + 15)
	{
		darthit = 1 + rand() % 20;

		cout << "dart hit " << darthit << endl;

		return darthit;
	}

	else
	{
		cout << "dart hit the wall " << endl;

		return 0;
	}

}


// throw double passes in throw variable from game and depending on player success rate will hit target or segment to left or right including the double of that segment with equal 5% chance otherwise will
// return 0 as the player has hit the wall
int DartBoard::throw_double(int successrate, int dartval) {




	int random = rand() % 100 + 1;


	if (random < successrate)
	{

		cout << " dart hit double " << dartval << endl;

		return 2 * dartval;
	}


	else if (random < successrate + 5)
	{


		cout << " dart missed and hit " << bd[1][dartval] << endl;


		return bd[1][dartval];
	}

	else if (random < successrate + 10)
	{

		cout << " dart missed and hit" << bd[0][dartval] << endl;


		return bd[0][dartval];
	}


	else if (random < successrate + 15)
	{

		cout << " dart missed and hit double " << bd[0][dartval] << endl;


		return 2 * bd[0][dartval];

	}

	else if (random < successrate + 20)

	{
		cout << " dart missed and hit double " << bd[1][dartval] << endl;



		return 2 * bd[1][dartval];
	}

	else if (random < successrate + 25)
	{

		cout << " dart missed the double but hit " << dartval << endl;



		return dartval;

	}

	else
	{

		cout << "dart hit the wall " << endl;


		return 0;
	}
}



// throw treble passes in throw variable from game and depending on player success rate will hit target or segment to left or right including the treble of that segment with equal 5% chance otherwise will
// return 0 as the player has hit the wall
int DartBoard::throw_treble(int successrate, int dartval)
{
	int random = rand() % 100 + 1;



	if (random < successrate)
	{

		cout << " dart hit triple " << dartval << endl;


		return 3 * dartval;
	}

	else if (random < successrate + 5)
	{


		cout << " dart missed and hit " << bd[1][dartval] << endl;


		return bd[1][dartval];
	}

	else if (random < successrate + 10)
	{

		cout << " dart missed and hit" << bd[0][dartval] << endl;


		return bd[0][dartval];
	}

	else if (random < successrate + 15)
	{

		cout << " dart missed and hit triple " << bd[0][dartval] << endl;


		return 3 * bd[0][dartval];

	}

	else if (random < successrate + 20)

	{
		cout << " dart missed and hit triple " << bd[1][dartval] << endl;



		return 3 * bd[1][dartval];
	}

	else if (random < successrate + 25)
	{

		cout << " dart missed the triple but hit " << dartval << endl;



		return dartval;

	}

	else
	{

		cout << " dart hit the wall " << endl;

		return 0;
	}

}

// throw bull only needs success rate and if success rate < random number then bull is hit otherwise it will return a random value 
// between 1 - 20 to simulate hitting a section around the bull 
int DartBoard::throw_bull(int successrate)
{

	int darthit = 0;

	int random = rand() % 100 + 1;

	if (random < successrate)

	{
		cout << "dart hit the bull" << endl;


		return 50;
	}
	else
	{
		darthit = 1 + rand() % 20;

		cout << "dart missed bullseye but hit " << darthit << endl;;

		return darthit;
	}

}


// this simulates a game of closest to the bull to determine which player goes first success rate is hard coded to 50 % to simulate a 50/ 50 chance 
// spaced out numbers after success rate to cover the other 50 points the score could land on for a more realistic simulation 
int DartBoard::ClosestToBull(int successrate)
{

	successrate = 50;

	int random = rand() % 100 + 1;



	if (random < successrate)
	{
		cout << "Bull Hit" << endl;

		return 50;
	}


	if (random < successrate + 10)
	{
		cout << " Dart landed 2mm from the bull " << endl;
		return 40;
	}

	if (random < successrate + 29)

	{
		cout << " Dart landed 4mm from the bull " << endl;

		return 30;

	}

	if (random < successrate + 39)

	{
		cout << " Dart landed 6mm from the bull " << endl;

		return 20;

	}

	if (random < successrate + 40)

	{
		cout << " Dart landed 6.5mm from bull " << endl;

		return 10;
	}

	else
	{
		cout << " Dart missed the board " << endl;

		return 0;
	}

}

// this is a modified throw_bull function and adds the possibility to hit the outer bull 
int DartBoard::throw_bull501(int successrate)
{

	int darthit = 0;

	int random = rand() % 100 + 1;

	if (random < successrate)
	{
		cout << "dart hit the bull" << endl;;

		return 50;
	}
	if (random < successrate + 5)
	{
		cout << "dart hit the outer bull" << endl;;

		return 25;
	}
	else
	{
		darthit = 1 + rand() % 20;

		cout << "dart missed bullseye and hit " << darthit << endl;;

		return darthit;
	}

}





int DartBoard::GetDartThrow()
{
	return Dart_Throw;
}



void DartBoard::SetDartThrow(int dartval)
{
	Dart_Throw = dartval;
}


