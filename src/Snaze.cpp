#include <iostream>
#include "Snake.h"
#include "Level.h"
#include "SnakeGame.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>  

using namespace std;

int main(int argc, char *argv[]){
	vector <string> linhas;
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
  while (getline(file, linha)) {
  	if(linha == "&"){
			cout<<"ola";
 			ofstream outfile;
			outfile.open("./temp/test.txt");
			for(int i=0; i<linhas.size(); i++) { 
				outfile << linhas[i];
			}	
			outfile.close();
			linhas.clear();
  	}
		else{	
			linhas.push_back(linha);
		}
  }	
  file.close();*/
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
