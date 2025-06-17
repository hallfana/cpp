#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string str);
		~Weapon();
		std::string getType(void);
		void setType(std::string);
};

#endif