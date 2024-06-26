/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:47:56 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 22:57:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

/* CONSTRUCTORS */

Span::Span(void) : _N(0), _occupancy(0){
	std::cout << "Span default constructor called" << std::endl;
	return;
}

Span::Span(const unsigned int N) : _N(N), _occupancy(0){
	std::cout << "Span param constructor called with " << N << " elements" << std::endl;
	return;
}

Span::Span(const Span& other){
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
	return;
}

Span::~Span(void){
	std::cout << "Span destructor called" << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Span&	Span::operator=(const Span& rhs){
	
	if (this != &rhs){
		this->_N = rhs._N;
		this->_occupancy = rhs._occupancy;
		for (unsigned int i = 0; i < _occupancy; i++)
			this->_vec[i] = rhs._vec[i];
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	Span::addNumber(const int x){
	if (this->_occupancy >= this->_N)
		throw std::runtime_error("error: container full");
	this->_vec.push_back(x);
	this->_occupancy++;
	return;
}

void	Span::printElements(void){
	for (unsigned int i = 0; i < this->_occupancy; i++)
		std::cout << this->_vec[i] << std::endl;
	return;
}

unsigned int	Span::shortestSpan(void){
	int	minDiff = INT_MAX;
	
	if (this->_occupancy < 2)
		throw std::runtime_error("error: not enough elements for span");
		
	// Sort vector in increasing order
	std::sort(this->_vec.begin(), this->_vec.end());
	for (unsigned int i = 0; i < this->_occupancy - 1; i++){
		if (this->_vec[i + 1] - this->_vec[i] < minDiff)
			minDiff = this->_vec[i + 1] - this->_vec[i];
	}
	return minDiff;
}

/* Vector is sorted in increasing order. Return difference between last and
first element. Iterator of end() needs to be moved back by 1 to point on
last element. */
unsigned int	Span::longestSpan(void){
	if (this->_occupancy < 2)
		throw std::runtime_error("error: not enough elements for span");
	std::sort(this->_vec.begin(), this->_vec.end());
	return *(this->_vec.end() - 1) - *(this->_vec.begin());
}
