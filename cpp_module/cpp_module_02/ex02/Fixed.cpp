#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = raw << this->bit;
}

Fixed::Fixed(const float raw)
{
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(raw * (1 << this->bit));
}

Fixed::Fixed(const Fixed &ref)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->value = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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
	//std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed &ref) const
{
	return this->value > ref.value;
}

bool Fixed::operator<(const Fixed &ref) const
{
	return this->value < ref.value;
}

bool Fixed::operator>=(const Fixed &ref) const
{
	return this->value >= ref.value;
}

bool Fixed::operator<=(const Fixed &ref) const
{
	return this->value <= ref.value;
}

bool Fixed::operator==(const Fixed &ref) const
{
	return this->value == ref.value;
}

bool Fixed::operator!=(const Fixed &ref) const
{
	return this->value != ref.value;
}

Fixed Fixed::operator+(const Fixed &ref) const
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed Fixed::operator-(const Fixed &ref) const
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed Fixed::operator*(const Fixed &ref) const
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	return Fixed(this->toFloat() / ref.toFloat());
}

Fixed &Fixed::operator++()
{
	value++;
	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

const Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	value--;
	return temp;
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& ref)
{
	os << ref.toFloat();
	return os;
}