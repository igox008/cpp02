/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/30 22:51:14 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	triangleArea(Point const &A, Point const &B, Point const &C)
{
    float _a = A.get_x().toFloat() * (B.get_y().toFloat() - C.get_y().toFloat());
    float _b = B.get_x().toFloat() * (C.get_y().toFloat() - A.get_y().toFloat());
    float _c = C.get_x().toFloat() * (A.get_y().toFloat() - B.get_y().toFloat());
    return (0.5 * (_a + _b + _c));
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
    float   main_triangle = triangleArea(a, b, c);
    float   area1 = triangleArea(point, b, c);
    float   area2 = triangleArea(a, point, c);
    float   area3 = triangleArea(a, b, point);
    return (main_triangle == area1 + area2 + area3);
}
