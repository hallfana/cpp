#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name){
	Zombie* zomb = new Zombie(name);
	return zomb;
}