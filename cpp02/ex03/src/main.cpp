/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:40:49 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 17:45:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

void	test(const Point& a, const Point& b, const Point& c, const Point& p, \
	const int i){
	if (bsp(a, b, c, p))
		std::cout << "Point" << i << " is inside the triangle." << std::endl;
	else
		std::cout << "Point" << i << " is outside the triangle." << std::endl;
	return;
}

int	main(void){
	Point	a(0.0, 0.0);
	Point	b(5.0, 0.0);
	Point	c(2.5, 4.0);

	Point*	points = new Point[9];
	
	// Points inside the triangle
	points[0] = Point(2.0, 1.0);
	points[1] = Point(3.0, 2.0);
	points[2] = Point(1.0, 3.0);

	// Points outside the triangle
	points[3] = Point(6.0, 2.0);
	points[4] = Point(1.0, -1.0);
	points[5] = Point(3.0, 5.0);

	// Points on the edges of the triangle
	points[6] = Point(2.5, 0.0);
	points[7] = Point(0.0, 2.0);
	points[8] = Point(5.0, 2.0);
	
	for (int i = 0; i < 9; i++)
		test(a, b, c, points[i], i);
	delete [] points;
	return 0;
}
