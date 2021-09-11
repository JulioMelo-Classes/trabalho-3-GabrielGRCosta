#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Snake{
private:
 	pair<int,int> cabeca;
	pair<int,int> save_point;
	int vida;
	vector <pair<int,int>> cauda;
	char direcao;
	int Comida;
	int score;

public:
	Snake(string arquivo);
	Snake(Snake* parametro);

	int get_comida();
	void move(char m);
	void increase();
	bool check_phead(int l, int c);
	pair<int,int> phead();
	pair<int,int> token(char oden);
	char get_direcao();
	pair<int,int> get_save();
	int get_vida();
	bool check_pbody(pair<int,int> pos);
	void copiar_body(vector<pair<int,int>>* body);
	void respawn();
	void more_food();
	void add_score(int a);
	int get_score();
};

#endif
