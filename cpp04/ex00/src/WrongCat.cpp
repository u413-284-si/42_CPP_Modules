/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 14:08:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/* CONSTRUCTORS */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
	std::cout << "[WrongCat] default constructor called." << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal("WrongCat"){
	*this = other;
	std::cout << "[WrongCat] copy constructor called." << std::endl;
	return;
}

WrongCat::~WrongCat(void){
	std::cout << "[WrongCat] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

WrongCat&	WrongCat::operator=(const WrongCat& rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	WrongCat::makeSound(void) const{
	std::cout << "[WrongCat]: ooooooaaaaim" << std::endl;
	return;
}
