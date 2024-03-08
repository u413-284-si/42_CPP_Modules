/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:50:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 16:08:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

/* CONSTRUCTORS */

Ice::Ice(void) : AMateria("ice"){
	if (VERBOSE)
		std::cout << "[Ice] default constructor called." << std::endl;
	return;
}

Ice::Ice(const Ice& other) : AMateria(other){
	if (VERBOSE)
		std::cout << "[Ice] copy constructor called." << std::endl;
	*this = other;
	return;
}

Ice::~Ice(void){
	if (VERBOSE)
		std::cout << "[Ice] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Ice&	Ice::operator=(const Ice& rhs){
	/* if (this != &rhs)
		this->_type = rhs.getType(); */
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

AMateria*	Ice::clone(void) const{
	return new Ice(*this);
}

void		Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	return;
}
