#include "strategy.hpp"
#include <stdlib.h>

const int flatPrice = 1000;
const int housePrice = 4000;
const int flatPay = 500;
const int housePay = 2000;

void Greedy::step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random){
	if (stillInGame()){
		index = (index + random) % m;
		int sw = map[index].type;
			if (sw == 0){ // if its a House
				if (cash() >= flatPrice && map[index].owner == -1){ // if it has no owner & has enough cash
					map[index].owner = i;
					_cash = _cash - flatPrice;
					std::cout<< _name << " has bought a flat " << std::endl;
				}
				else if (cash() >= housePrice && map[index].owner == i && !map[index].hasHouse) { // if it's his flat, without a house & has enough cash for it
					map[index].hasHouse = true;
					_cash = _cash - housePrice;
					std::cout<< _name << " stepped on his flat so he bought a house for " << housePrice << std::endl;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && !map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, no house on it
					thisMuch = flatPay;
					_cash = _cash - flatPay;
					std::cout<< _name << " stepped on a flat -500 for him, +500 for the other one" << std::endl;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, has house on it
					thisMuch = housePay;
					_cash = _cash - housePay;
					std::cout<< _name << " stepped on a house -2k for him, +2k for the other one" << std::endl;
				}
				else{
					thisMuch = 0;
				}
			}
			else if (sw == 1){ // if its Lucky
				addCash(map[index].value);
				std::cout<< _name << " was lucky and won " << map[index].value << std::endl;
			}
			else if (sw == 2){ // if its Service
				addCash(-map[index].value);
				std::cout<< _name << " wasnt lucky and had to pay " << map[index].value << std::endl;
			}
	}
}

void Careful::step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random){
	if (stillInGame()){
		int budget = cash() / 2;
		index = (index + random) % m;
		int sw = map[index].type;
		if (sw == 0){
			if (budget >= flatPrice && map[index].owner == -1){ // if it has no owner & has enough cash
					map[index].owner = i;
					_cash = _cash - flatPrice;
					std::cout<< _name << " has bought a flat " << std::endl;
				}
				else if (budget >= housePrice && map[index].owner == i && !map[index].hasHouse) { // if it's his flat, without a house & has enough cash for it
					map[index].hasHouse = true;
					_cash = _cash - housePrice;
					std::cout<< _name << " stepped on his flat so he bought a house for " << housePrice << std::endl;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && !map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, no house on it
					thisMuch = flatPay;
					_cash = _cash - flatPay;
					std::cout<< _name << " stepped on a flat -500 for him, +500 for the other one" << std::endl;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, has house on it
					thisMuch = housePay;
					_cash = _cash - housePay;
					std::cout<< _name << " stepped on a house -2k for him, +2k for the other one" << std::endl;
				}
				else{
					thisMuch = 0;
				}
		}
		else if (sw == 1){ // if its Lucky
			_cash+=map[index].value;
		}
		else if (sw == 2){ // if its Service
			_cash-=map[index].value;
		}
	}
}
void Tactician::step(std::vector<Map> &map, int m, int i, int &giveHim, int &thisMuch, int random){
	if (stillInGame()){
		l = true;
		index = (index + random) % m;
		int sw = map[index].type;
		if (sw == 0 ){
			if (l && cash() >= flatPrice && map[index].owner == -1){ // if it has no owner & has enough cash
					map[index].owner = i;
					_cash = _cash - flatPrice;
					std::cout<< _name << " has bought a flat " << std::endl;
					l = false;
				}
				else if (l && cash() >= housePrice && map[index].owner == i && !map[index].hasHouse) { // if it's his flat, without a house & has enough cash for it
					map[index].hasHouse = true;
					_cash = _cash - housePrice;
					std::cout<< _name << " stepped on his flat so he bought a house for " << housePrice << std::endl;
					l = false;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && !map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, no house on it
					thisMuch = flatPay;
					_cash = _cash - flatPay;
					std::cout<< _name << " stepped on a flat -500 for him, +500 for the other one" << std::endl;
				}
				else if (map[index].owner!=-1 && map[index].owner!= i && map[index].hasHouse){
					giveHim = map[index].owner; //s1 else owns it, has house on it
					thisMuch = housePay;
					_cash = _cash - housePay;
					std::cout<< _name << " stepped on a house -2k for him, +2k for the other one" << std::endl;
				}
				else{
					thisMuch = 0;
				}
		}
		else if (sw == 1){ // if its Lucky
			_cash+=map[index].value;
		}
		else if (sw == 2){ // if its Service
			_cash-=map[index].value;
		}
	}
}