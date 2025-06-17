#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _nombre;
		static const int _decimal;
	public:
		Fixed();
		Fixed(Fixed &obj);
		Fixed &operator=(Fixed &fixed_copy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif