/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:28:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 13:10:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/* CONSTRUCTORS */

PresidentialPardonForm::PresidentialPardonForm(void) : 	AForm("presidential_pardon", 25, 5),
														_target("undefined"){
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Default constructor called." << std::endl;
	return;												
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :	AForm("presidential_pardon", 25, 5),
																			_target(target){
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Param constructor called." << std::endl;
	return;																			
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other){
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Copy constructor called." << std::endl;
	*this = other;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Destructor called." << std::endl;
	return;		
}

/* OPERATOR OVERLOADING */

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] Copy assignment operator called." << std::endl;
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const{
		checkExec(executor);
		std::cout << this->_target << " has been pardoned by ";
		std::cout << "His Majesty Zaphod Beeblebrox." << std::endl;
		return;	
}
