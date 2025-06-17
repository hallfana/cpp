#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string str) {
	this->type = str;
}

Weapon::~Weapon() {
	this->type = "";
}

void Weapon::setType(std::string str) {
	this->type = str;
}

std::string Weapon::getType(void) {
	return this->type;
}