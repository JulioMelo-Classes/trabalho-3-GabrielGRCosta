#include "SnakeGame.h"
#include "Level.h"

#include <iostream>
#include <fstream>

#include <chrono>
#include <thread>

using namespace std;

SnakeGame::SnakeGame(string arquivo) : cobra(arquivo), nivel(arquivo, &cobra) {
  this->choice = "";
  this->frameCount = 0;
	
  initialize_game();
}

void SnakeGame::initialize_game(){
	state = RUNNING;
}

void SnakeGame::process_actions(){
	switch(state){
		case WAITING_USER:
			cin>>std::ws>>choice;
			break;
		default:
			break;
	}
}

void SnakeGame::update(){
	switch(state){
		case RUNNING:
			if (frameCount>0 && frameCount%10 == 0) {
				state = WAITING_USER;
				break;
			}

			//cantinho do galvao
			//for(auto& i : {1,2,3,4,5,6,7,8,9,10}){
				for(int i=0; i<10; i++){ 
    			this->cobra.move('N');	
			}	
			//cantinho do galvao

			break;
		case WAITING_USER:
			if (choice == "n"){
				state = GAME_OVER;
				game_over();
			}
			else{
				state = RUNNING;
			}
			break;
		default:
			break;
	}
}

void wait(int ms){
	this_thread::sleep_for(chrono::milliseconds(ms));
}

void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

void SnakeGame::render(){
	clearScreen();
	switch(state){
		case RUNNING:
			this->nivel.gerar_mapa();
			break;
		case WAITING_USER:
			cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
			break;
		case GAME_OVER:
			cout<<"O jogo terminou!"<<endl;
			break;
	}
	frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
	while(state != GAME_OVER){
		process_actions();
		update();
		render();
		wait(1000);
	}
}