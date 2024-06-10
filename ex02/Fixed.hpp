/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:34:33 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/10 19:44:57 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
	private:
		int					fixed_point;
		static const int	frac_bits;
	public:
		Fixed();
		Fixed(Fixed const &_fixed);
		Fixed(const int _int_);
		Fixed(const float _float_);
		~Fixed();
		Fixed &operator=(Fixed const &_fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt( void ) const;

		bool	operator>(Fixed _fixed_) const;
		bool	operator>=(Fixed _fixed_) const;
		bool	operator<(Fixed _fixed_) const;
		bool	operator<=(Fixed _fixed_) const;
		bool	operator==(Fixed _fixed_) const;
		bool	operator!=(Fixed _fixed_) const;

		Fixed	operator+(Fixed _fixed_) const;
		Fixed	operator-(Fixed _fixed_) const;
		Fixed	operator*(Fixed _fixed_) const;
		Fixed	operator/(Fixed _fixed_) const;

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &f1, Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&min(Fixed const &f1, Fixed const &f2);
		static const Fixed	&max(Fixed const &f1, const Fixed &f2);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &_fixed_);        

#endif