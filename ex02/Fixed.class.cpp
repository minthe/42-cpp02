/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/11 14:04:05 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"


// CONSTRUCTORS ************************************************ CONSTRUCTORS

 
Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->_fixed_point = value * (1 << this->_fractional_bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->_fixed_point = roundf(value * (1 << this->_fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		this->_fixed_point = rhs.getRawBits();
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}


// FUNCTIONS *************************************************** FUNCTIONS


int		Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_fixed_point / (1 << this->_fractional_bits));
}

int		Fixed::toInt() const
{
	return (this->_fixed_point / (1 << this->_fractional_bits));
}


// OVERLOADS *************************************************** OVERLOADS


bool	Fixed::operator<(const Fixed& rhs) const
{
	if (this->toFloat() < rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (rhs._fixed_point < this->_fixed_point);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return !(this->_fixed_point > rhs._fixed_point);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return !(this->_fixed_point < rhs._fixed_point);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_fixed_point == rhs._fixed_point);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return !(this->_fixed_point == rhs._fixed_point);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++() // prefix incrementation
{
	this->_fixed_point++;
	return (*this); // return new value by reference
}

Fixed&	Fixed::operator--() // prefix decrementation
{
	this->_fixed_point--;
	return (*this); // return new value by reference
}

Fixed	Fixed::operator++(int) // postfix incrementation
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int) // postfix decrementation
{
	Fixed tmp = *this;
	operator--();
	return (tmp);
}

// STATICS ***************************************************** STATICS


const int	Fixed::_fractional_bits = 8;

std::ostream & operator<<(std::ostream & o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return (o);
}
