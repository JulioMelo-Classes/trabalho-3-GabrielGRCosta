#include <iostream>
#include "Snake.h"
#include "Level.h"
#include "SnakeGame.h"
#include <fstream>
#include <sstream>
#include <string>  

using namespace std;

int main(int argc, char *argv[]){

	if (argc < 2){
		return -1;
	}
	string arquivo(argv[1]);
	
 	/*ifstream file(arquivo);
        if (!file.is_open()){
      		cout<<"Arquivo não encontrado"<<endl;
                  exit(1);
    	}
        string linha;
        stringstream ss;
        while (getline(file, linha)) {
        	if(linha == " "){
 			ofstream outfile ("test.txt");
			outfile.close();
        	}
        }	
       	file.close();*/
       	SnakeGame game(arquivo);

       game.loop();

  return 0;
}
