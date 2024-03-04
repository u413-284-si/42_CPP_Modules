/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 13:56:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/* CONSTRUCTORS */

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal"){
	std::cout << "[WrongAnimal] default constructor called." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const std::string& typus) : _type(typus){
	std::cout << "[WrongAnimal] param constructor called." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
	std::cout << "[WrongAnimal] copy constructor called." << std::endl;
	return;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "[WrongAnimal] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

WrongAnimal&		WrongAnimal::operator=(const WrongAnimal& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

const std::string&	WrongAnimal::getType(void) const{
	return this->_type;
}

void				WrongAnimal::makeSound(void) const{
	std::cout << "[WrongAnimal]: Yells weirdly" << std::endl;
	return;
}
