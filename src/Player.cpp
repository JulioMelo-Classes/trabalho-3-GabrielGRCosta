#include <iostream>
#include <vector>
#include <random>
#include "Player.h"
#include "Snake.h"
#include "Level.h"


using namespace std;

Player::Player(Snake* cobra, Level* nivel){
	this->cobra = cobra;
        vector <pair<int,int>> cauda;
	this->nivel = nivel;
	this->score = 0;
}

bool Player::find_solution(){
	direcoes.clear();
	int limit=0;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distrib(0, 3);
	Snake cobratoken(cobra);
	do {
		int direcao = distrib(mt);
		switch(direcao){
			case 0:
				if(cobratoken.get_direcao() == 'S' ||
                                   nivel->check_pos(cobratoken.token('N')) == '#' ||								     
				   cobratoken.check_pbody(cobratoken.token('N')) == true){
					break;
				}
				cobratoken.move('N');
				direcoes.push_back('N');
				break;
			case 1:
				if(cobratoken.get_direcao() == 'N' ||
				   nivel->check_pos(cobratoken.token('S')) == '#' ||
				   cobratoken.check_pbody(cobratoken.token('S')) == true){
					break;
				}
				cobratoken.move('S');
				direcoes.push_back('S');
				break;
			case 2:
				if(cobratoken.get_direcao() == 'O' ||
				   nivel->check_pos(cobratoken.token('L')) == '#' ||
				   cobratoken.check_pbody(cobratoken.token('L')) == true){
					break;
				}
				cobratoken.move('L');
				direcoes.push_back('L');
				break;
			case 3:
				if(cobratoken.get_direcao() == 'L' ||
				   nivel->check_pos(cobratoken.token('O')) == '#' ||
				   cobratoken.check_pbody(cobratoken.token('O')) == true){
					break;
				}
				cobratoken.move('O');
				direcoes.push_back('O');
				break;
			default:
				cobratoken.move('N');
				direcoes.push_back('N');
				break;
		}
		limit++;
	} while (nivel->pfood() != cobratoken.phead() && limit < 500);

	if (nivel->pfood() == cobratoken.phead()) {
		return true;
	}else{
    		cobratoken.move(cobratoken.get_direcao());
    		direcoes.push_back(cobratoken.get_direcao());
		return false;
	}
}

int Player::get_score(){
	int score = 0;
	if(direcoes.size() < 5){
		score += 100;
	}
	else if(direcoes.size() > 5 && direcoes.size() < 15){
		score += 50;
	}
	else if(direcoes.size() > 50 && direcoes.size() < 100){
		score +=2;
	}
	return score;
}

bool Player::find_solution2(){
	vector <pair<int,int>> paths;
	direcoes.clear();
	Snake cobratoken(cobra);
  bool teste = find_solution3(cobratoken,paths);
	this->score = get_score();
	return teste;
}


bool Player::test_move(char d, vector <pair<int,int>> &paths,Snake &cobra){
	char l;
	int k=0;
	switch(d){
		case 'N':
			l = 'S';
			break;
		case 'S':
			l = 'N';
			break;
		case 'L':
			l = 'O';
			break;
		case 'O':
			l = 'L';
			break;
	} 

	for(int i=0; i<paths.size(); i++){
		if(cobra.token(d) == paths[i]){
			return false;
		}
	}
	if(cobra.get_direcao() == l  ||
	   nivel->check_pos(cobra.token(d)) == '#' ||
	   cobra.check_pbody(cobra.token(d)) == true ){
		return false;
	}else{
		return true;
	}
}
	

bool Player::find_solution3(Snake cobrinha, vector <pair<int,int>>&paths){
	if (nivel->pfood() == cobrinha.phead()) 
		return true;
	paths.push_back(cobrinha.phead()); 
	if (test_move('L',paths,cobrinha)) {
		Snake cobrao(cobrinha);
		cobrao.move('L');
		direcoes.push_back('L');
		if (find_solution3(cobrao,paths)) {
			return true;
		}
		direcoes.pop_back();
	}
	if (test_move('N',paths,cobrinha)) {
		Snake cobrao(cobrinha);
		cobrao.move('N');
		direcoes.push_back('N');
		if (find_solution3(cobrao,paths)) {
			return true;
		}
		direcoes.pop_back();
	}
	if (test_move('S',paths,cobrinha)) {
		Snake cobrao(cobrinha);
		cobrao.move('S');
		direcoes.push_back('S');
		if (find_solution3(cobrao,paths)) {
			return true;
		}
		direcoes.pop_back();
	} 
	if (test_move('O',paths,cobrinha)) {
		Snake cobrao(cobrinha);
		cobrao.move('O');
		direcoes.push_back('O');
		if (find_solution3(cobrao,paths)) {
			return true;
		}
		direcoes.pop_back();
	}
	paths.pop_back();
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

