/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:40:49 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 23:48:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

void	test(const Point& a, const Point& b, const Point& c, const Point& p){
	if (bsp(a, b, c, p))
		std::cout << "Point" << p << " is inside the triangle." << std::endl;
	else
		std::cout << "Point" << p << " is outside the triangle." << std::endl;
	return;
}

int	main(void){
	Point	a(0.0, 0.0);
	Point	b(5.0, 0.0);
	Point	c(2.5, 4.0);

	// Points inside the triangle
	Point	p1(2.0, 1.0);
	Point	p2(3.0, 2.0);
	Point	p3(1.0, 1.0);

	// Points outside the triangle
	Point	p4(6.0, 2.0);
	Point	p5(1.0, -1.0);
	Point	p6(3.0, 5.0);

	// Points on the edges of the triangle
	Point	p7(2.5, 0.0);
	Point	p8(0.0, 0.0);
	Point	p9(5.0, 0.0);
	
	std::cout << "Triangle with a" << a << ", b" << b << ", c" << c << ":" << std::endl;
	test(a, b, c, p1);
	test(a, b, c, p2);
	test(a, b, c, p3);
	test(a, b, c, p4);
	test(a, b, c, p5);
	test(a, b, c, p6);
	test(a, b, c, p7);
	test(a, b, c, p8);
	test(a, b, c, p9);

	return 0;
}
