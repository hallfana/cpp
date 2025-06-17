#include "Fixed.hpp"

const int Fixed::_decimal = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_nombre = 0;
}

Fixed::Fixed(Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (&src != this)
	{
			this->_nombre = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nombre;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_nombre = raw;
}