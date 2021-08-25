#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Level.h"
#include "Snake.h"

using namespace std;

class Player{
private:
	vector <char> direcoes;
public:
	bool find_solution();
	char next_move();
};


#endif