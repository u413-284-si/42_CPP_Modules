/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:23:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 15:32:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : mFixedValue(0){
	if (VERBOSE)
		std::cout << "Default constructor called" << std::endl;
	return;
}

// Constructor with int parameter
Fixed::Fixed(const int num) : mFixedValue(num << msFracBits){
	if (VERBOSE)
		std::cout << "Int constructor called" << std::endl;
	return;	
}

// Constructor with float parameter
Fixed::Fixed(const float num) : mFixedValue((int)roundf(num * (1 << msFracBits))){
	if (VERBOSE)
		std::cout << "Float constructor called" << std::endl;
	return;
}

// Copy constructor
Fixed::Fixed(const Fixed& other){
	if (VERBOSE)
		std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

// Destructor
Fixed::~Fixed(void){
	if (VERBOSE)
		std::cout << "Destructor called" << std::endl;
	return;
}

/* MEMBER FUNCTIONS */
int		Fixed::getRawBits(void) const{
	return this->mFixedValue;
}

void	Fixed::setRawBits(int const raw){
	this->mFixedValue = raw;
	return;
}

float	Fixed::toFloat(void) const{
	return (float)mFixedValue / (1 << msFracBits); // at least one operand has to be float
}

int		Fixed::toInt(void) const{
	return (int)roundf((float)mFixedValue / (1 << msFracBits));
}

/* OPERATOR OVERLOADING */

// Copy assignment operator

Fixed&	Fixed::operator= (const Fixed& rhs){
	if (VERBOSE)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->mFixedValue = rhs.getRawBits();
	return *this;
}

// Comparison operators

bool	Fixed::operator>(const Fixed& rhs) const{
	return this->mFixedValue > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed& rhs) const{
	return this->mFixedValue < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed& rhs) const{
	return this->mFixedValue >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed& rhs) const{
	return this->mFixedValue <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed& rhs) const{
	return this->mFixedValue == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed& rhs) const{
	return this->mFixedValue != rhs.getRawBits();
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed& rhs) const{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment operators

Fixed&	Fixed::operator++(void){
	++(this->mFixedValue);
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	original = *this;
	++(this->mFixedValue);
	return original;
}

Fixed&	Fixed::operator--(void){
	--(this->mFixedValue);
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	original = *this;
	--(this->mFixedValue);
	return original;
}

Fixed&			Fixed::min(Fixed& a, Fixed& b){
	return a < b ? a : b;
}

Fixed&			Fixed::max(Fixed& a, Fixed& b){
	return a > b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	return a < b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	return a > b ? a : b;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}
