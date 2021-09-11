#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "Snake.h"

using namespace std;


Snake::Snake(string arquivo){
	ifstream file(arquivo);
	if (!file.is_open()){
    cout<<"Arquivo não encontrado"<<endl;
		exit(1);
  }
	
	string linha;
	getline(file, linha);
	int a=0;
	while(getline(file, linha)){
		int b=0;	
		for (auto& c : linha) {
			if (c == '*') {
				this->cabeca = make_pair(a, b);
				this->save_point = make_pair(a,b);
			}
			b++;
		}
		a++;
	}
	file.close();
	this->vida = 5;
	this->direcao = 'N';
	this->Comida = 0;
	this->score = 0;
}

Snake::Snake(Snake* parametro){
	this->cabeca = parametro->phead();
	this->save_point = parametro->get_save();
	this->vida = parametro->get_vida();
	parametro->copiar_body(&(this->cauda));
	this->direcao = parametro->get_direcao();
}

int Snake::get_comida(){
	return Comida;
}

void Snake::move(char m){
	cauda.insert(cauda.begin(), make_pair(cabeca.first,cabeca.second));
	cauda.pop_back();

	switch(m){
		case 'N':
			cabeca.first--;
			direcao = 'N';
			break;
		case 'S':
			cabeca.first++;
			direcao = 'S';
			break;
		case 'L':
			cabeca.second++;
			direcao = 'L';
			break;
		case 'O':
			cabeca.second--;
			direcao = 'O';
			break;
	}
}

void Snake::increase(){
	//cout << "cresceu";
	//cauda.insert(cauda.begin(), make_pair(cabeca.first,cabeca.second));
	cauda.push_back(make_pair(cauda.back().first, cauda.back().second));
}

void Snake::more_food(){
	this->Comida++;
}

bool Snake::check_phead(int l, int c){
	if(l == cabeca.first && c == cabeca.second){
		return true;
	}
	return false;
}

pair<int,int> Snake::phead(){
	return cabeca;
}

pair<int,int> Snake::token(char oden){ // A MUDAR! DEVE RECEBER DIRECAO DO AI::NEXT_MOVE()
	switch(oden){
		case 'N':
			return make_pair(cabeca.first-1, cabeca.second);
		case 'S':
			return make_pair(cabeca.first+1, cabeca.second);
		case 'L':
			return make_pair(cabeca.first, cabeca.second+1);
		case 'O':
			return make_pair(cabeca.first, cabeca.second-1);
		default:
			return make_pair(0,0);
	}
}

char Snake::get_direcao(){
	return direcao;
}

pair<int,int> Snake::get_save(){
	return save_point;
}

int Snake::get_vida(){
	return vida;
}

bool Snake::check_pbody(pair<int,int> pos){
	for(auto& p : cauda){
		if(p.first == pos.first && p.second == pos.second){
			return true;
		}
	}
	return false;
}

void Snake::copiar_body(vector<pair<int,int>>* body){
	for (auto k : this->cauda){
		body->push_back(k);
	}	
}


void Snake::respawn(){
	this->vida--;
	this->cabeca = save_point;
	this->cauda.clear();
	this->direcao = 'N';
}

void Snake::add_score(int a){
	this->score += a;
} 

int Snake::get_score(){
	return score;
}
