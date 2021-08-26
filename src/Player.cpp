#include <iostream>
#include <vector>
#include <random>
#include "Snake.h"
#include "Level.h"
#include "Player.h"

using namespace std;

Player::Player(Snake* cobra, Level* nivel){
	this->cobra = cobra;
	this->nivel = nivel;
}

bool Player::find_solution(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distrib(0, 3);
	Snake cobratoken(cobra);
	do {
		int direcao = distrib(mt);
		//#
		switch(direcao){
			case 0:
				cobratoken.move('N');
				direcoes.push_back('N');
				break;
			case 1:
				cobratoken.move('S');
				direcoes.push_back('S');
				break;
			case 2:
				cobratoken.move('L');
				direcoes.push_back('L');
				break;
			case 3:
				cobratoken.move('O');
				direcoes.push_back('O');
				break;
		}
	} while (nivel->pfood() != cobratoken.phead() && direcoes.size() < 1000);

	if (nivel->pfood() == cobratoken.phead()) {
		return true;
	}
	return false;
}

char Player::next_move(){
}

