/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:11:53 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 11:44:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/* CONSTRUCTORS */

Brain::Brain(void){
	for (int i = 0; i < IDEA_CAPACITY; i++)
		this->_ideas[i] = "I think, therefore I am.";
	std::cout << "[Brain] default constructor called." << std::endl;
	return;
}

Brain::Brain(const Brain& other){
	for (int i = 0; i < IDEA_CAPACITY; i++)
		this->_ideas[i] = "I think I am a copy.";
	*this = other;
	std::cout << "[Brain] copy constructor called." << std::endl;
	return;
}

Brain::~Brain(void){
	std::cout << "[Brain] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Brain&	Brain::operator=(const Brain& rhs){
	if (this != &rhs){
		for (int i = 0; i < IDEA_CAPACITY; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	Brain::setIdea(const std::string& idea, int n){
	if (n < 0 || n >= IDEA_CAPACITY){
		std::cout << "Index out of bounds. Brain can't contain idea.\n";
		return;
	}
	this->_ideas[n] = idea;
	return;		
}

void	Brain::printIdea(int n) const{
	if (n < 0 || n >= IDEA_CAPACITY){
		std::cout << "Index out of bounds. Brain can't contain idea.\n";
		return;
	}
	std::cout << this->_ideas[n] << std::endl;
	return;
}
