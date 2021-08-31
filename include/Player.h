#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Level.h"
#include "Snake.h"

using namespace std;

class Player{
private:
	Snake* cobra;
	Level* nivel;
	vector<char> direcoes;
	int score;

public:
	Player(Snake* cobra, Level* nivel);

	bool find_solution();
	char next_move();
	bool direcoes_empty();
	int get_score();
};

#endif
