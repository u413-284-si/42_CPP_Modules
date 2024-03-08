/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:50:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 16:48:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

/* CONSTRUCTORS */

Cure::Cure(void) : AMateria("cure"){
	if (VERBOSE)
		std::cout << "[Cure] default constructor called." << std::endl;
	return;
}

Cure::Cure(const Cure& other) : AMateria(other){
	if (VERBOSE)
		std::cout << "[Cure] copy constructor called." << std::endl;
	*this = other;
	return;
}

Cure::~Cure(void){
	if (VERBOSE)
		std::cout << "[Cure] destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Cure&	Cure::operator=(const Cure& rhs){
	if (VERBOSE)
		std::cout << "[Cure] copy assignment operator called." << std::endl;
	/* if (this != &rhs)
		this->_type = rhs.getType(); */
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

AMateria*	Cure::clone(void) const{
	return new Cure(*this);
}

void		Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	return;
}
