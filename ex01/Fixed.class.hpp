/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:27 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/09 11:04:57 by vfuhlenb         ###   ########.fr       */
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

		Fixed(); // canonical default constructor
		Fixed(Fixed const & src); // canonical copy constructor
		~Fixed(); // canonical deconstructor

		Fixed &	operator=(Fixed const & rhs); // canonical assigment constructor (no new instance created)

	private:

		int					_fixed_point;
		static const int	_fractional_bits;
};

#endif
