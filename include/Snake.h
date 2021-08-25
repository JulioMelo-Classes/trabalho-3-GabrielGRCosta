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

public:
	Snake(string arquivo);

	void move(char m);
	void increase();
	bool check_phead(int l, int c);
	pair<int,int> phead();
};



#endif