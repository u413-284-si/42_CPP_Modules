/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 11:58:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/* CONSTRUCTORS */

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()){
	this->_brain->setIdea("My goodness, I'm a cat", 0);
	this->_brain->setIdea("Caress me hooman", 1);
	this->_lastIdea = 1;
	std::cout << "[Cat] default constructor called." << std::endl;
	return;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*(other._brain))),
								_lastIdea(other._lastIdea){
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
		*(this->_brain) = *(rhs._brain);
		this->_lastIdea = rhs._lastIdea;
	}
	std::cout << "[Cat] copy assignment operator called." << std::endl;
	return *this;
}

/* MEMBER FUNCTIONS */

void	Cat::makeSound(void) const{
	std::cout << "[Cat]: miaaaaaaooo" << std::endl;
	return;
}

void	Cat::printIdeas(void) const{
	for (int i = 0; i <= this->_lastIdea; i++){
		this->_brain->printIdea(i);		
	}
	std::cout << "Brain address at " << this->_brain << std::endl;
	std::cout << std::endl;
	return;
}

int		Cat::getLastIdea(void) const{
	return this->_lastIdea;
}

void	Cat::setLastIdea(int n){
	if (n < 0 || n >= IDEA_CAPACITY)
		this->_lastIdea = 0;
	this->_lastIdea = n;
	return;
}

void	Cat::setIdea(const std::string& idea, int n){
	this->_brain->setIdea(idea, n);
	return;
}
