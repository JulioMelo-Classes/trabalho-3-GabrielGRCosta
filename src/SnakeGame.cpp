#include "SnakeGame.h"
#include "Snake.h"
#include "Level.h"
#include "Player.h"

#include <iostream>
#include <fstream>

#include <chrono>
#include <thread>

using namespace std;

SnakeGame::SnakeGame(string arquivo) : cobra(arquivo), nivel(arquivo, &cobra), player(&cobra, &nivel)  {
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
			/*if (this->nivel.check_pos(this->cobra.token()) == '$') {
				this->nivel.generate_food();
    		this->cobra.increase();
			}
    	this->cobra.move(this->cobra.get_direcao());*/
			
			if (this->player.direcoes_empty())
				this->player.find_solution();
			char direcao = this->player.next_move();
			if (this->nivel.check_pos(this->cobra.token(direcao)) == '$') {
				this->nivel.generate_food();
    		this->cobra.increase();
			}
    	this->cobra.move(direcao);
			


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