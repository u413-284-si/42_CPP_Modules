/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 13:49:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/* CONSTRUCTORS */

Animal::Animal(void) : _type("Animal"){
	std::cout << "[Animal] default constructor called." << std::endl;
	return;
}

Animal::Animal(const std::string& typus) : _type(typus){
	std::cout << "[Animal] param constructor called." << std::endl;
	return;
}

Animal::Animal(const Animal& other){
	*this = other;
	std::cout << "[Animal] copy constructor called." << std::endl;
	return;
}

Animal::~Animal(void){
	std::cout << "[Animal] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Animal&	Animal::operator=(const Animal& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

const std::string&	Animal::getType(void) const{
	return this->_type;
}

void				Animal::makeSound(void) const{
	std::cout << "[Animal]: Humms curiously" << std::endl;
	return;
}
