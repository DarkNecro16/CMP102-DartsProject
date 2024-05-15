#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class DartBoard {

private:
	// pulls result from dartval in dartboard
	int Dart_Throw = 0;

	//getters and setters 
public:
	int throw_single(int success_rate, int dartval);
	int throw_single501(int successrate, int dartval);
	int throw_double(int successrate, int dartval);
	int throw_treble(int successrate, int dartval);
	int throw_bull(int sucess_rate);
	int throw_bull501(int successrate);
	int ClosestToBull(int successrate);
	int GetDartThrow();
	void SetDartThrow(int dartval);

protected:

	//is the values next to the value you are throwing for

	int bd[2][21]{
		{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
		{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1}
	};


};