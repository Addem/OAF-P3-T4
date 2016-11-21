#include <vector>
#include <iostream>
#ifndef KAPPA
#define KAPPA

struct Map{
	int owner; // if -1 -> has no owner
	int value;
	bool hasHouse;
	int type; // 0 is for House, 1 is for Lucky, 2 is for Service
};

class Strategy {
	protected:
		std::string _name;
		int _cash;
		int index;
		Strategy(std::string a) : _name(a){ _cash = 10000; index = 0; }

	public:
		int cash() {return _cash;}
		void addCash(int k) { _cash += k; }
		virtual void step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random) = 0;
		std::string nev() const {return _name;}
		bool stillInGame() { return _cash > 0 ;} 
		virtual ~Strategy() {}
	
};

class Greedy : public Strategy{
	public:
		Greedy(std::string a) : Strategy(a){};
		void step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random);
};
class Careful : public Strategy{
	public:
		Careful(std::string a) : Strategy(a){};
		void step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random);
};
class Tactician : public Strategy{
	public:
		Tactician(std::string a) : Strategy(a){};
		void step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random);
		bool l;
};

#endif