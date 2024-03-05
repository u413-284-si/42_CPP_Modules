/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:11:53 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/04 17:18:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/* CONSTRUCTORS */

Brain::Brain(void){
	std::cout << "[Brain] default constructor called." << std::endl;
	return;
}

Brain::Brain(const Brain& other){
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
		this->ideas = rhs.ideas;
	}
	return *this;
}
