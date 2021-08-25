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
}

void Snake::move(char m){
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
	char a= 'o';
	cauda.push_back(make_pair(1,2));
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