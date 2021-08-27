#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <utility>
#include "Snake.h"
#include "Level.h"


using namespace std;

Level::Level(string arquivo, Snake* cobra) {
	this->cobra = cobra;

	ifstream file(arquivo);
	if (!file.is_open()){
    cout<<"Arquivo não encontrado"<<endl;
		exit(1);
  }
	string linha;
	stringstream ss;
	getline(file, linha);
	ss<<linha;
	ss>>this->Altura>>this->Largura>>this->NumComidas;
	while (getline(file, linha)) {
		this->Mapa.push_back(linha);
	}
	file.close();

	this->save_food = make_pair(0,0);
	generate_food();
}

void Level::generate_food(){
	if (Mapa[save_food.first][save_food.second] == '$')
		Mapa[save_food.first][save_food.second] = ' ';
	int num1;
	int num2;
	std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<unsigned> distrib(0, this->Altura-1);
  std::uniform_int_distribution<unsigned> distrib2(0, this->Largura-1); 
  num1=distrib(mt);
	num2=distrib2(mt);
	while(Mapa[num1][num2] != ' '){ //Mapa
    num1=distrib(mt);
		num2=distrib2(mt);
	}
	Mapa[num1][num2] = '$';
	save_food = make_pair(num1,num2);
}

void Level::gerar_mapa(){
	for(int i=0; i<this->Altura; i++){
		for(int j=0; j<this->Largura; j++){
			if (this->Mapa[i][j] == '*')
				this->Mapa[i][j] = ' ';// isso aqui pode gerar um bug
			if (this->cobra->check_phead(i, j) == true)
				cout<<'@'; //V < > ^
			else if (this->cobra->check_pbody(make_pair(i, j)) == true)
				cout<<'o';
			else
				cout<<this->Mapa[i][j];
		}
		cout << endl;
	}
}

pair<int,int> Level::pfood(){
	return save_food;
}

char Level::check_pos(pair<int,int> pos){
	return Mapa[pos.first][pos.second];
}