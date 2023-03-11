/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:27 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/11 18:16:17 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {

	public:

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static			Fixed&	max(Fixed& f1, Fixed& f2);
		static const	Fixed&	max(const Fixed& f1, const Fixed& f2);
		static			Fixed&	min(Fixed& f1, Fixed& f2);
		static const	Fixed&	min(const Fixed& f1, const Fixed& f2);

		Fixed(); // canonical default constructor
		Fixed(const int value); // parametric constructor
		Fixed(const float value); // parametic constructor
		Fixed(Fixed const & src); // canonical copy constructor
		~Fixed(); // canonical deconstructor

		Fixed&	operator=(Fixed const & rhs); // canonical assigment constructor (no new instance created)

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const; // const because the two operands of binary operation are not changed
		Fixed	operator-(const Fixed& rhs) const; // same as above
		Fixed	operator*(const Fixed& rhs) const; // same as above
		Fixed	operator/(const Fixed& rhs) const; // same as above

		Fixed&	operator++(); // prefix incrementation (returns reference to incremented object)
		Fixed&	operator--(); // prefix decrementation (returns reference to decremented object)
		Fixed	operator++(int); // postfix incrementation
		Fixed	operator--(int); // postfix decrementation

	private:

		int					_fixed_point;
		static const int	_fractional_bits;

};

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs);

#endif
