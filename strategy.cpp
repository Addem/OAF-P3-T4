#include "strategy.hpp"
#include <stdlib.h>
#include <time.h>

void Greedy::Step(){
	index = 0;
	if (stillInGame()){
		int random;
		srand (time(NULL));
		random = rand()%6 + 1; // generates random number between 1 and 6
		
		
	}
}