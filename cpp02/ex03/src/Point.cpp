/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:50:15 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 23:50:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point(void) : mX(0), mY(0){
	if (VERBOSE)
		std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point(const float& m, const float& n) : mX(m), mY(n){
	if (VERBOSE)
		std::cout << "Parameterised constructor called" << std::endl;
	return;											
}

Point::Point(const Point& other) : mX(other.mX), mY(other.mY){
	if (VERBOSE)
		std::cout << "Copy constructor called" << std::endl;
	return;
}

Point::~Point(void){
	if (VERBOSE)
		std::cout << "Destructor called" << std::endl;
	return;
}

Point&	Point::operator=(const Point& rhs){
	if (VERBOSE)
		std::cout << "Copy assignment operator called, but all attributes are const and can't be changed" << std::endl;
	(void)rhs;
	return *this;
}

// FUNCTIONS

float	Point::getmX(void) const{
	return this->mX.toFloat();
}

float	Point::getmY(void) const{
	return this->mY.toFloat();
}

float	Point::sign2DCrossProduct(const Point& a, const Point& b, const Point& p){
	Fixed	tmp;

	// Compute the cross product of vectors (b - a) and (p - a)
	tmp = (b.mX - a.mX) * (p.mY - a.mY) - (p.mX - a.mX) * (b.mY - a.mY);
	return tmp.toFloat();
}

std::ostream&	operator<<(std::ostream& os, const Point& p){
	os << "(" << p.getmX() << ", " << p.getmY() << ")";
	return os;
}
