/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/05 17:35:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/* CONSTRUCTORS */

Cat::Cat(void) : Animal("Cat"){
	this->_brain = new Brain();
	std::cout << "[Cat] default constructor called." << std::endl;
	return;
}

Cat::Cat(const Cat& other) : Animal("Cat"){
	*this = other;
	std::cout << "[Cat] copy constructor called." << std::endl;
	return;
}

Cat::~Cat(void){
	delete this->_brain; 
	std::cout << "[Cat] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Cat&	Cat::operator=(const Cat& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs._brain);
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	Cat::makeSound(void) const{
	std::cout << "[Cat]: miaaaaaaooo" << std::endl;
	return;
}
