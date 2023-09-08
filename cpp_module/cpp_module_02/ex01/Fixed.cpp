#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = raw << this->bit;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(raw * (1 << this->bit));
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = ref.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat() const
{
	return (float)this->value / (1 << this->bit);
}

int Fixed::toInt() const
{
	return this->value >> this->bit;
}

std::ostream& operator<<(std::ostream &os, const Fixed &ref)
{
	os << ref.toFloat();
	return os;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}