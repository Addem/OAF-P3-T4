#include "strategy.hpp"
#include <stdlib.h>
#include <time.h>

const int flatPrice = 1000;
const int housePrice = 4000;
const int flatPay = 500;
const int housePay = 2000;

void Greedy::step(){
	if (stillInGame()){
		int random;
		srand (time(NULL));
		random = rand()%6 + 1; // generates random number between 1 and 6
		std::cout<<random;
		
	}
}
void Careful::step(){
	if (stillInGame()){
		int random;
		srand (time(NULL));
		random = rand()%6 + 1; // generates random number between 1 and 6
		std::cout<<random;
		
	}
}
void Tactician::step(){
	if (stillInGame()){
		int random;
		srand (time(NULL));
		random = rand()%6 + 1; // generates random number between 1 and 6
		std::cout<<random;
		
	}
}