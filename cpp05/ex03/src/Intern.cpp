/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:47:07 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 20:00:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"


/* CONSTRUCTORS */

Intern::Intern(void){
	if (VERBOSE)
		std::cout << "[Intern] Default constructor called." << std::endl;
	return;
}

Intern::Intern(const Intern& other){
	if (VERBOSE)
		std::cout << "[Intern] Copy constructor called." << std::endl;
	*this = other;
	return;
}

Intern::~Intern(void){
	if (VERBOSE)
		std::cout << "[Intern] Destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Intern&		Intern::operator=(const Intern& rhs){
	if (VERBOSE)
		std::cout << "[Intern] Copy assignment operator called." << std::endl;
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

AForm*	Intern::makeForm(const std::string formName, const std::string target) const{
	AForm*	formPtr = NULL;
	int		form;
	
	form = convertForm(formName);
	std::cout << "Intern ";
	switch (form)
	{
	case 0:{
		std::cout << "creates " << formName << std::endl;
		AForm*	p = new PresidentialPardonForm(target);
		formPtr = p;
		break;
	}
	case 1:{
		std::cout << "creates " << formName << std::endl;
		AForm* r = new RobotomyRequestForm(target);
		formPtr = r;
		break;
	}
	case 2:{
		std::cout << "creates " << formName << std::endl;
		AForm*	s = new ShrubberyCreationForm(target);
		formPtr = s;
		break;
	}
	default:{
		std::cerr << "cant't create " << formName << " because ";
		throw WrongFormException();
		break;
	}
	}
	return formPtr;
}

int		Intern::convertForm(const std::string formName) const{
	const std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++){
		if (formName == forms[i])
			return i;
	}
	return -1;
}
