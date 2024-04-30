/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:25:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/30 22:54:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const float _x_, const float _y_) : x(_x_), y(_y_)
{
}

Point::Point(Point &_point_) : x(_point_.x), y(_point_.y)
{
}

Point	&Point::operator=(Point &_point_)
{
	(void)_point_;
	return (*this);
}

const Fixed	&Point::get_x(void) const {return (this->x);}

const Fixed	&Point::get_y(void) const {return (this->y);}

std::ostream	&operator<<(std::ostream &out, const Point &_point_)
{
	out << "x: " << _point_.get_x().toFloat() << ", y: " << _point_.get_y().toFloat();
	return (out);
}
