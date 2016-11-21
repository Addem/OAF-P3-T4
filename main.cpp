#include "strategy.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main(){
std::ifstream f("test.txt");
int m;
f >> m;
std::vector<Map> map(m);
for (int i = 0; i<m; ++i){
	char c;
	int val;
	f >> c;
	switch (c){
		case 'h' : map[i].owner = -1; map[i].hasHouse = false; map[i].type = 0; break;
		case 'l' : f>>val; map[i].value = val; map[i].type = 1; break;
		case 's' : f>>val; map[i].value = val; map[i].type = 2; break;
	}
}
int n;
f>>n;
std::vector<Strategy*> strat(n);

for (int i = 0; i < n; ++i){
	std::string name;
	char type;
	f>>name>>type;
	switch (type){
		case 'G' : strat[i] = new Greedy(name);break;
		case 'C' : strat[i] = new Careful(name);break;
		case 'T' : strat[i] = new Tactician(name);break;
	}
}

int random;
srand (time(NULL));
random = rand()%6 + 1; // generates random number between 1 and 6
int inGame = n;
int giveHim;
int thisMuch = 0;
bool losers[n];
for (int i = 0; i<n; ++i) losers[i] = false;

while (inGame > 1){
	for (int i = 0; i < n; ++i){
			strat[i]->step(map, m, i, giveHim, thisMuch, random);
			if (!strat[i]->stillInGame() && !losers[i]){//if the player lost all his money during the step
				--inGame;
				losers[i] = true;
				for (int j = 0; j < m; ++j){
					if (map[j].owner == i){
						map[j].owner = -1;
						!map[j].hasHouse;
					}
				}
			}
			if (thisMuch != 0) strat[giveHim]->addCash(thisMuch);
			std::cout << strat[i]->nev() << " has " << strat[i]->cash() <<" money in the bank " << std::endl;
			random = rand()%6 + 1;
			thisMuch = 0;
	}
}
for (int i = 0; i < n; ++i){
	if (strat[i]->stillInGame()) std::cout<< "Winner: " << strat[i]->nev() << std::endl;
}

for (int i = 0; i < n; ++i) delete strat[i];
}