#include "strategy.h"
#include <iostream>
#include <fstream>
#include <vector>

struct Map{
	std::string owner;
	const int value;
	bool hasHouse;
};

ifstream f("test.txt")
int m;
f >> m;
vector<Map> map(m);
for (int i = 0; i<m; ++i){
	char c;
	int val;
	f >> c;
	switch (c){
		case 'h' : map[i].owner = ""; map[i].hasHouse = false; break;
		case 'l' : f>>val; map[i].value = val; break;
		case 's' : f>>val; map[i].value = val; break;
	}
}

int n;
f>>n;
vector<Strategy*> strat(n);

for (int i = 0; i < n; ++i){
	std::string name;
	char type;
	f>>name>>type;
	switch (type){
		case 'G' : new Greedy(name);break;
		case 'C' : new Careful(name);break;
		case 'T' : new Tactician(name);break;
	}
}



for (int i = 0; i < n; ++i) delete strat[i];