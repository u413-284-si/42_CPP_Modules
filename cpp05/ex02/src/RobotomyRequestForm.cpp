/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:28:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 13:02:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"

/* CONSTRUCTORS */

RobotomyRequestForm::RobotomyRequestForm(void) : 	AForm("robotomy", 72, 45),
													_target("undefined"){
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Default constructor called." << std::endl;
	return;												
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :	AForm("robotomy", 72, 45),
																		_target(target){
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Param constructor called." << std::endl;
	return;																			
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other){
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Copy constructor called." << std::endl;
	*this = other;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Destructor called." << std::endl;
	return;		
}

/* OPERATOR OVERLOADING */

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] Copy assignment operator called." << std::endl;
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const{
		checkExec(executor);
		srand(time(0)); // use current time as seed for random number generator
		std::cout << "* Rrrrrrr zZZzzBzzz clonk tingeling*" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->_target << " has been robotomised successfully!\n";
		else
			std::cout << "Robotomy on " << this->_target << " failed. He dead.\n";
		return;		
}
