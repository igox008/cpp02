/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:34:33 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/29 16:44:26 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>

class Fixed
{
	private:
		int					fixed_point;
		static const int	frac_bits;
	public:
		Fixed();
		Fixed(Fixed &_fixed);
		~Fixed();
		Fixed &operator=(Fixed &_fixed);
		int	getRawBits(void);
		void	setRawBits(int const raw);
};


#endif