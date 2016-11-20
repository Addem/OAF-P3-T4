#ifndef KAPPA
#define KAPPA

#include <vector>
#include <iostream>

class Strategy {
	protected:
		std::string _name;
		int _cash;
		vector<int> _owned;
		Strategy(std::string a) : _name(a){ _cash = 10000; }

	public:
		virtual void step();
		std::string nev() const (return _nev;)
		bool stillInGame() const { return cash > 0 ;} 
		virtual ~Strategy() {}
	
};

class Greedy : public Strategy{
	public:
		Greedy(std::string a) : Strategy(a);
		void step();
}
class Careful : public Strategy{
	public:
		Careful(std::string a) : Strategy(a);
		void step();
}
class Tactician : public Strategy{
	public:
		Tactician(std::string a) : Strategy(a);
		void step();
}




#endif