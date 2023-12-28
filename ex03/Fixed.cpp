/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:20 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:55 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------------------------------ CONSTRUCTORS --------------------------------

Fixed::Fixed(void) : _fixedPointValue(0) {}

Fixed::Fixed(const int num) : _fixedPointValue(num << Fixed::_fractionalBits) {}

Fixed::Fixed(const float num) : _fixedPointValue(roundf(num * (1 << Fixed::_fractionalBits))) {}

Fixed::Fixed(const Fixed &src) : _fixedPointValue(src.getRawBits()) {}

Fixed::~Fixed(void) {}

// --------------------------- ARITHMETIC OPERATORS ---------------------------

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// --------------------------- COMPARISON OPERATORS ---------------------------

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

// ---------------------- INCREMENT AND DECREMENT OPERATORS -------------------

Fixed	&Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_fixedPointValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_fixedPointValue--;
	return (tmp);
}

// --------------------------- MIN AND MAX FUNCTIONS --------------------------

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}

// ------------------------------ MEMBER FUNCTIONS -----------------------------

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> Fixed::_fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << Fixed::_fractionalBits));
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

// ------------------------------ NON MEMBER OVERLOADS ------------------------

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}
