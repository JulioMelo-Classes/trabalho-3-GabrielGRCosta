#include <iostream>
#include "Snake.h"
#include "Level.h"
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){

	if (argc < 2){
		return -1;
	}
	string arquivo(argv[1]);

  SnakeGame game(arquivo);

  game.loop();

  return 0;
}