#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
	private :
	public :
		std::string name;
		Zombie	();
		~Zombie	(void);
		void announce();
};

Zombie* zombieHorde( int N, std::string name ) ;

#endif