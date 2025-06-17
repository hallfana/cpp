#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}
HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &club) {
	this->_weapon = &club;
}

void HumanB::attack(void) {
	if (this->_weapon == NULL)
		std::cout << this->_name << " has no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
}