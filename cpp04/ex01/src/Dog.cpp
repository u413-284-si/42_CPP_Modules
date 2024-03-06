/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/06 18:06:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog(void) : Animal("Dog"){
	this->_brain = new Brain();
	this->_brain->setIdea("Hola die Waldfee!", 0);
	this->_brain->setIdea("Throw the bone!", 1);
	this->_curIdea = 1;
	std::cout << "[Dog] default constructor called." << std::endl;
	return;
}

Dog::Dog(const Dog& other) : Animal("Dog"){
	*this = other;
	std::cout << "[Dog] copy constructor called." << std::endl;
	return;
}

Dog::~Dog(void){
	delete this->_brain;
	std::cout << "[Dog] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Dog&	Dog::operator=(const Dog& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs._brain);
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	Dog::makeSound(void) const{
	std::cout << "[Dog]: wuff wuf" << std::endl;
	return;
}

void	Dog::printIdeas(void) const{
	for (int i = 0; i <= this->_curIdea; i++){
		this->_brain->printIdea(i);		
	}
}

int		Dog::getCurIdea(void) const{
	return this->_curIdea;
}
