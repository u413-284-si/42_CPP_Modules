/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 19:08:33 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog(void) : Animal("Dog"){
	std::cout << "[Dog] default constructor called." << std::endl;
	return;
}

Dog::Dog(const Dog& other) : Animal("Dog"){
	*this = other;
	std::cout << "[Dog] copy constructor called." << std::endl;
	return;
}

Dog::~Dog(void){
	std::cout << "[Dog] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Dog&	Dog::operator=(const Dog& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	Dog::makeSound(void) const{
	std::cout << "[Dog]: wuff wuf" << std::endl;
	return;
}
