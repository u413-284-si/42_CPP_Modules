/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:47:27 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/14 18:59:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

/* CONSTRUCTORS */

ShrubberyCreationForm::ShrubberyCreationForm(void) : 	AForm("shrub", 145, 137),
														_target("undefined"){
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Default constructor called." << std::endl;
	return;												
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :	AForm("shrub", 145, 137),
																			_target(target){
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Param constructor called." << std::endl;
	return;																			
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other){
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Copy constructor called." << std::endl;
	*this = other;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Destructor called." << std::endl;
	return;		
}

/* OPERATOR OVERLOADING */

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] Copy assignment operator called." << std::endl;
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	try{
		checkExec(executor);
	}
	catch(std::exception& e){
		std::cerr << "Can't create shrubbery because ";
		std::cerr << e.what() << std::endl;
	}
	else{
		
	}
}
