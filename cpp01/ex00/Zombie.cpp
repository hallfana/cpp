#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << this->name << " woke up" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " died (again)" << std::endl;
}

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}