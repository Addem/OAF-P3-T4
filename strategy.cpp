#include "strategy.h"
#include <stdlib.h>
#include <time.h>

void Greedy::Step(){
	if (stillInGame()){
		int random = (rand()%6) + 1;
		srand (time(NULL));
		random = rand()%6 + 1; // generates random number between 1 and 6
		
	}
}