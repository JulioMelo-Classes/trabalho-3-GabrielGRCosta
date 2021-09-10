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
	bool find_solution2();
	bool find_solution3(Snake cobrinha, vector <pair<int,int>>&paths);
	bool test_move(char d, vector <pair<int,int>> &paths,Snake &cobra);
	char next_move();
	bool direcoes_empty();
	int get_score();
};

#endif
