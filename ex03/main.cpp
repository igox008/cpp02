/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:43:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/12 02:34:41 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point	A(0, 0);
	const Point	B(4, 0);
	const Point	C(2, 3);
	const Point	P(1, 1);

	if (bsp(A, B, C, P))
		std::cout << "the Point P " << P << " is inside the triangle ABC\n";
	else
		std::cout << "the Point P " << P << " is not inside the triangle ABC\n";
	return (0);
}