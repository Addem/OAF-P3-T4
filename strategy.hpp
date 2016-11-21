#include <vector>
#include <iostream>
#ifndef KAPPA
#define KAPPA


class Strategy {
	protected:
		std::string _name;
		int _cash;
		std::vector<int> _owned;
		Strategy(std::string a) : _name(a){ _cash = 10000; index = 0; }
		int index;

	public:
		virtual void step() = 0;
		std::string nev() const {return _name;}
		bool stillInGame() { return _cash > 0 ;} 
		virtual ~Strategy() {}
	
};

class Greedy : public Strategy{
	public:
		Greedy(std::string a) : Strategy(a){};
		void step();
};
class Careful : public Strategy{
	public:
		Careful(std::string a) : Strategy(a){};
		void step();
};
class Tactician : public Strategy{
	public:
		Tactician(std::string a) : Strategy(a){};
		void step();
};




#endif