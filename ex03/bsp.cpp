/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/12 02:46:15 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void triangleArea(Point const &A, Point const &B, Point const &C, Fixed &r)
{
    Fixed _a = A.get_x() * (B.get_y() - C.get_y());
    Fixed _b = B.get_x() * (C.get_y() - A.get_y());
    Fixed _c = C.get_x() * (A.get_y() - B.get_y());
    r = (_a + _b + _c) * Fixed(0.5f);
    if (r < Fixed(0))
        r = Fixed(-1) * r;
    
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
    Fixed   main_triangle;
    triangleArea(a, b, c, main_triangle);
    Fixed   area1;
    triangleArea(point, b, c, area1);
    Fixed   area2;
    triangleArea(a, point, c, area2);
    Fixed   area3;
    triangleArea(a, b, point, area3);
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    return (main_triangle == area1 + area2 + area3);
}
