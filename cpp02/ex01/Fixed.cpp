#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(int raw) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = raw << this->_bits;
}

Fixed::Fixed(float raw) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(raw * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (&src != this)
	{
			this->_fixed = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

float Fixed::toFloat(void) const {
	return((float)this->_fixed / (float)(1 << this->_bits));
}

int Fixed::toInt(void)const{
	return(this->_fixed >> this->_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}