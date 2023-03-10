/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:27 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/09 18:14:33 by vfuhlenb         ###   ########.fr       */
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

		Fixed(); // canonical default constructor
		Fixed(const int value); // parametric constructor
		Fixed(const float value); // parametic constructor
		Fixed(Fixed const & src); // canonical copy constructor
		~Fixed(); // canonical deconstructor

		Fixed &	operator=(Fixed const & rhs); // canonical assigment constructor (no new instance created)
		// Fixed	operator<<()

	private:

		int					_fixed_point;
		static const int	_fractional_bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
