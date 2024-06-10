/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:29:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/10 19:29:01 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::frac_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default contructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed &_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl; // if (this != &fixed)
	this->fixed_point = _fixed.fixed_point;
	return (*this);
}

Fixed::Fixed(Fixed &_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = _fixed;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->fixed_point = raw;
}
