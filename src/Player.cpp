#include <iostream>
#include <vector>
#include <random>
#include "../include/Snake.h"
#include "../include/Level.h"
#include "../include/Player.h"

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
        if(cobratoken.get_direcao() == 'S' || check_pos(cobratoken.token('N')) == '#' || check_pos(cobratoken.token('N')) == 'o'){
          break;
        }
				cobratoken.move('N');
				direcoes.push_back('N');
				break;
			case 1:
        if(cobratoken.get_direcao() == 'N' || check_pos(cobratoken.token('S')) == '#' || check_pos(cobratoken.token('S')) == 'o'){
          break;
        }
				cobratoken.move('S');
				direcoes.push_back('S');
				break;
			case 2:
        if(cobratoken.get_direcao() == 'O' || check_pos(cobratoken.token('L')) == '#' || check_pos(cobratoken.token('L')) == 'o'){
          break;
        }
				cobratoken.move('L');
				direcoes.push_back('L');
				break;
			case 3:
        if(cobratoken.get_direcao() == 'L' || check_pos(cobratoken.token('O')) == '#' || check_pos(cobratoken.token('O')) == 'o'){
          break;
        }
				cobratoken.move('O');
				direcoes.push_back('O');
				break;
		}
	} while (nivel->pfood() != cobratoken.phead() && direcoes.size() < 1000);

	if (nivel->pfood() == cobratoken.phead()) {
		return true;
	}
  while(check_pos(cobratoken.phead()) != '#' || check_pos(cobratoken.phead()) != 'o'){
    cobratoken.move(get_direcao())
    direcoes.push_back(get_direcao())
  }
	return false;
}

char Player::next_move(){
	char deca = direcoes[0];
	direcoes.erase(direcoes.begin());
	return deca;
}

bool Player::direcoes_empty(){
	if(direcoes.size() == 0){
		return true;
	}
	return false;
}

