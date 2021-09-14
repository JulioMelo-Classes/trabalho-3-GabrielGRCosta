#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Level.h"
#include "Player.h"

using namespace std;

class SnakeGame{
public:
  enum GameStates{
    RUNNING,
    GAME_OVER,
    WAITING_USER
  };

private:
  Snake cobra;
  Level nivel;
  Player player;
  int frameCount;
  std::string choice;
  GameStates state;
             
public:
  SnakeGame(string arquivo);
	void loop();
     
private:
  void initialize_game();
  void update();
  void process_actions();
  void render();
  void game_over();
	
};

#endif
