/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:29:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/12 03:19:24 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::frac_bits = 8;

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &_fixed)
{
	this->fixed_point = _fixed.fixed_point;
	return (*this);
}

Fixed::Fixed(Fixed const &_fixed)
{
	this->setRawBits(_fixed.getRawBits());
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

Fixed::Fixed(const float _float_)
{
	this->fixed_point = (int)roundf(_float_ * (1 << this->frac_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (float)(1 << this->frac_bits));
}

Fixed::Fixed(const int _int_)
{
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

bool	Fixed::operator>(Fixed _fixed_) const {return (this->toFloat() > _fixed_.toFloat());}

bool	Fixed::operator>=(Fixed _fixed_) const {return (this->toFloat() >= _fixed_.toFloat());}

bool	Fixed::operator<(Fixed _fixed_) const {return (this->toFloat() < _fixed_.toFloat());}

bool	Fixed::operator<=(Fixed _fixed_) const {return (this->toFloat() <= _fixed_.toFloat());}

bool	Fixed::operator==(Fixed _fixed_) const {return (this->toFloat() == _fixed_.toFloat());}

bool	Fixed::operator!=(Fixed _fixed_) const {return (this->toFloat() != _fixed_.toFloat());}

Fixed	Fixed::operator+(Fixed _fixed_) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() + _fixed_.getRawBits()));
	return (ret);
}

Fixed	Fixed::operator-(Fixed _fixed_) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() - _fixed_.getRawBits()));
	return (ret);
}

Fixed	Fixed::operator*(Fixed _fixed_) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() * _fixed_.getRawBits()) / 256);
	return (ret);
}

Fixed	Fixed::operator/(Fixed _fixed_) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() / _fixed_.getRawBits()) * 256);
	return (ret);
}

Fixed	Fixed::operator++() {return (this->fixed_point++, *this);}

Fixed	Fixed::operator--() {return (this->fixed_point--, *this);}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->fixed_point++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->fixed_point--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2) {return (f1.getRawBits() < f2.getRawBits() ? f1 : f2);}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2) {return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}

const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2) {return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}

const Fixed	&Fixed::max(Fixed const &f1, const Fixed &f2) {return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}
