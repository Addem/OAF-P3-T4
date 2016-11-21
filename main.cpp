#include "strategy.hpp"
#include <vector>
#include <iostream>
#include <fstream>

struct Map{
	std::string owner;
	int value;
	bool hasHouse;
	bool forSale;
	int type; // 0 is for House, 1 is for Lucky, 2 is for Service
};

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
		case 'h' : map[i].owner = ""; map[i].hasHouse = false; map[i].forSale = true; map[i].type = 0; break;
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

for (int i = 0; i < m; ++i){
	int sw;
	sw = map[i].type;
	switch(sw){
		case 0 : std::cout<<map[i].owner<< "<-ove a haz  " << std::endl; break;
		case 1 : std::cout<< "lucky value: " << map[i].value << std::endl; break;
		case 2 : std::cout<< "service value: " << map[i].value << std::endl; break;
	}
	
}

for ( int i = 0; i < n ; ++i){
	strat[i]->step;
}

for (int i = 0; i < n; ++i) delete strat[i];
}