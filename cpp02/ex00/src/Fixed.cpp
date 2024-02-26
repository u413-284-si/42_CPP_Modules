/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:41:30 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/26 22:03:14 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : mFixedValue(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

// Copy constructor
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

// Copy assignment operator
Fixed&	Fixed::operator= (const Fixed& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->mFixedValue = rhs.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->mFixedValue;
}

void	Fixed::setRawBits(int const raw){
	this->mFixedValue = raw;
	return;
}
