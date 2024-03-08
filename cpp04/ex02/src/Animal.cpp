/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 13:49:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/* CONSTRUCTORS */

AAnimal::AAnimal(void) : _type("AAnimal"){
	std::cout << "[AAnimal] default constructor called." << std::endl;
	return;
}

AAnimal::AAnimal(const std::string& typus) : _type(typus){
	std::cout << "[AAnimal] param constructor called." << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal& other){
	*this = other;
	std::cout << "[AAnimal] copy constructor called." << std::endl;
	return;
}

AAnimal::~AAnimal(void){
	std::cout << "[AAnimal] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

AAnimal&	AAnimal::operator=(const AAnimal& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

const std::string&	AAnimal::getType(void) const{
	return this->_type;
}
