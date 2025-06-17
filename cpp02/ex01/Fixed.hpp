#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixed;
		static const int _bits;
	public:
		Fixed();
		Fixed(int const raw);
		Fixed(float const raw);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &fixed_copy);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &op, Fixed const &fixed);


#endif