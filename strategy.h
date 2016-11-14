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
		virtual void build();
		virtual void buy();
		virtual void pay();
		std::string nev() const (return _nev;)
		bool stillInGame() const { return cash > 0 ;} 
		virtual ~Strategy() {}
	
};




#endif