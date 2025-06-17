#include "Zombie.hpp"

int	main() {
	Zombie* z = NULL;

	z = z->newZombie("Zeus");
	z->announce();
	z->randomChump("leblond");
	delete z;
}