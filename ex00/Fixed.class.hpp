/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:27 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/03/11 19:13:43 by vfuhlenb         ###   ########.fr       */
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
		Fixed(const Fixed& src); // canonical copy constructor
		~Fixed(); // canonical deconstructor

		Fixed&	operator=(const Fixed& rhs); // canonical assigment constructor (no new instance created)

	private:

		int					_fixed_point;
		static const int	_fractional_bits;
};

#endif
