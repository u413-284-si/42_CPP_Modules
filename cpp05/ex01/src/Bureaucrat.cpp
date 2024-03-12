/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:21:37 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/13 00:07:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/* CONSTRUCTORS */

Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(1){
	if (VERBOSE)
		std::cout << "[Bureaucrat] Default constructor called." << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name){
	if (VERBOSE)
		std::cout << "[Bureaucrat] Param constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :	_name(other.getName()),
													_grade(other.getGrade()){
	if (VERBOSE)
		std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void){
	if (VERBOSE)
		std::cout << "[Bureaucrat] Destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& rhs){
	if (VERBOSE)
		std::cout << "[Bureaucrat] Copy assignment operator called." << std::endl;
	if (this != &rhs){
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

/* MEMBER FUNCTIONS */

const std::string&	Bureaucrat::getName(void) const{
	return this->_name;
}

int					Bureaucrat::getGrade(void) const{
	return this->_grade;
}

void				Bureaucrat::incrGrade(void){
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return;	
}

void				Bureaucrat::decrGrade(void){
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return;	
}
