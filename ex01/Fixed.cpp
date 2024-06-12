/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:29:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/12 02:07:13 by alaassir         ###   ########.fr       */
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

Fixed	&Fixed::operator=(Fixed const &_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = _fixed.fixed_point;
	return (*this);
}

Fixed::Fixed(Fixed const &_fixed)
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

Fixed::Fixed(const float _float_)
{
	std::cout << "Float parametrized contructor called" << std::endl;
	this->fixed_point = (int)roundf(_float_ * (1 << this->frac_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (float)(1 << this->frac_bits));
}

Fixed::Fixed(const int _int_)
{
	std::cout << "Int parametrized contructor called" << std::endl;
	this->fixed_point = _int_ << this->frac_bits;
}

int	Fixed::toInt(void) const
{
	return ((unsigned int)this->fixed_point >> this->frac_bits);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &_fixed_)
{
	out << _fixed_.toFloat();
	return (out);
}