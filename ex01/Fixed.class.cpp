/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/09 22:53:40 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

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

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}


Fixed &	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixed_point = rhs.getRawBits();
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}

int		Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_fixed_point / (1 << this->_fractional_bits));}

int		Fixed::toInt() const
{
	return (this->_fixed_point / (1 << this->_fractional_bits));
}

const int	Fixed::_fractional_bits = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
