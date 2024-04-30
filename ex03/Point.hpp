/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:18:46 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/30 22:51:28 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"


class   Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float _x_, const float _y_);
		Point(Point &_point_);
		Point	&operator=(Point &_point_);
		~Point();
		const Fixed	&get_x(void) const;
		const Fixed	&get_y(void) const;
};

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point);

std::ostream	&operator<<(std::ostream &out, const Point &_point_);

#endif
