/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:10 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 15:32:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void) : _type("undefined"){
	if (VERBOSE)
		std::cout << "[AMateria] default constructor called." << std::endl;
	return;
}

AMateria::AMateria(const std::string& type) : _type(type){
	if (VERBOSE)
		std::cout << "[AMateria] param constructor called." << std::endl;
	return;
}

AMateria::AMateria(const AMateria& other){
	if (VERBOSE)
		std::cout << "[AMateria] copy constructor called." << std::endl;
	*this = other;
	return;
}

AMateria::~AMateria(void){
	if (VERBOSE)
		std::cout << "[AMateria] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

AMateria&	AMateria::operator=(const AMateria& rhs){
	if (this != &rhs){
		this->_type = rhs.getType();
	}
	return *this;
}

/* MEMBER FUNCTIONS */

const std::string&	AMateria::getType(void) const{
	return this->_type;
}
