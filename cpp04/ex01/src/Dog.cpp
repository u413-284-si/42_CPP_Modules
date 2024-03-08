/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 11:51:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()){
	this->_brain->setIdea("Hola die Waldfee!", 0);
	this->_brain->setIdea("Throw the bone!", 1);
	this->_lastIdea = 1;
	std::cout << "[Dog] default constructor called." << std::endl;
	return;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*(other._brain))),
								_lastIdea(other._lastIdea){
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
		*(this->_brain) = *(rhs._brain);
		this->_lastIdea = rhs._lastIdea;
	}
	std::cout << "[Dog] copy assignment operator called." << std::endl;
	return *this;
}

/* MEMBER FUNCTIONS */

void	Dog::makeSound(void) const{
	std::cout << "[Dog]: wuff wuf" << std::endl;
	return;
}

void	Dog::printIdeas(void) const{
	for (int i = 0; i <= this->_lastIdea; i++){
		this->_brain->printIdea(i);		
	}
	std::cout << "Brain address at " << this->_brain << std::endl;
	std::cout << std::endl;
	return;
}

int		Dog::getLastIdea(void) const{
	return this->_lastIdea;
}

void	Dog::setLastIdea(int n){
	if (n < 0 || n >= IDEA_CAPACITY)
		this->_lastIdea = 0;
	this->_lastIdea = n;
	return;
}

void	Dog::setIdea(const std::string& idea, int n){
	this->_brain->setIdea(idea, n);
	return;
}
