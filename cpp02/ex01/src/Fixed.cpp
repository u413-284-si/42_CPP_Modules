/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:23:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 00:32:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : mFixedValue(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

// Constructor with int parameter
Fixed::Fixed(const int num) : mFixedValue(num << msFracBits){
	std::cout << "Int constructor called" << std::endl;
	return;	
}

// Constructor with float parameter
Fixed::Fixed(const float num) : mFixedValue((int)roundf(num * (1 << msFracBits))){
	std::cout << "Float constructor called" << std::endl;
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
	return this->mFixedValue;
}

void	Fixed::setRawBits(int const raw){
	this->mFixedValue = raw;
	return;
}

float	Fixed::toFloat(void) const{
	return (float)(mFixedValue / (1 << msFracBits));
}

int		Fixed::toInt(void) const{
	return (int)roundf((float)(mFixedValue / (1 << msFracBits)));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}