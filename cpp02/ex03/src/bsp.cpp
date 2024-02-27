/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:17:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 17:27:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

/**
 * @brief In the context of a 2D space and a triangle defined by three vertices
 * (a, b, and c), the sign of the cross product between vectors formed by these
 * vertices and a test point can be used to determine the relative position of 
 * the point with respect to the edges of the triangle.

 * Consider the vectors:
 * AB : Vector from vertex A to vertex B.
 * BC : Vector from vertex B to vertex C.
 * CA : Vector from vertex C to vertex A.
 * AP : Vector from vertex A to the test point P.
 * BP : Vector from vertex B to the test point P.
 * CP : Vector from vertex C to the test point P.
 * 
 * sign1=AB×AP
 * sign2=BC×BP
 * sign3=CA×CP
 * The sign of each cross product indicates the orientation of the vectors.
 * Specifically, it determines whether the test point is to the left or right
 * of the corresponding triangle edge (in a 2D sense).
 * 
 * If sign1, sign2​ and sign3 are all negative, the test point P is to the right
 * of all three edges, meaning it is inside the triangle.
 * 
 * If sign1, sign2​ and sign3​ are all positive, the test point P is to the left 
 * of all three edges, also indicating that it is inside the triangle.
 * 
 * If the signs have mixed values, it means the test point is on different sides
 * of different edges, and therefore, it is outside the triangle.
 * 
 * @param a 		Vertice a
 * @param b 		Vertice b
 * @param c 		Vertice c
 * @param point 	Test point
 * @return true 	If point is inside the triangle
 * @return false 	If point is outside the triangle
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point){
	float	sign1, sign2, sign3;

	// Calculate the signs of the point with respect to each of the triangle's edges
	sign1 = Point::sign2DCrossProduct(b, a, point);
	sign2 = Point::sign2DCrossProduct(c, b, point);
	sign3 = Point::sign2DCrossProduct(a, c, point);
	return 	(sign1 < 0 && sign2 < 0 && sign3 < 0) || (sign1 > 0 && sign2 > 0 && sign3 > 0);
}
