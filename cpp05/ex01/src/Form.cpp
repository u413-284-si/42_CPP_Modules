/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:43:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/13 01:03:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

/* CONSTRUCTORS */

Form::Form(void) : _name("undefined"), _signed(false), _gradeSign(10), _gradeExec(20){
	if (VERBOSE)
		std::cout << "[Form] Default constructor called." << std::endl;
	return;
}

Form::Form(const std::string& name, int gradeSign, int gradeExec) :	_name(name),
																	_signed(false),
																	_gradeSign(gradeSign),
																	_gradeExec(gradeExec){
	if (VERBOSE)
		std::cout << "[Form] Param constructor called." << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	return;
}

Form::Form(const Form& other) :	_name(other.getName()),
								_signed(other.getSigned()),
								_gradeSign(other.getGradeSign()),
								_gradeExec(other.getGradeExec()){
	if (VERBOSE)
		std::cout << "[Form] Copy constructor called." << std::endl;
	return;
}

Form::~Form(void){
	if (VERBOSE)
		std::cout << "[Form] Destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

Form&		Form::operator=(const Form& rhs){
	if (VERBOSE)
		std::cout << "[Form] Copy assignment operator called." << std::endl;
	if (this != &rhs){
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Form& f){
	os << f.getName() << ", form min. sign grade " << f.getGradeSign() << ".\n";
	os << f.getName() << ", form min. exec grade " << f.getGradeExec() << ".\n";
	os << f.getName() << ", form signed: " << f.getSigned() << ".";
	return os;
}

/* MEMBER FUNCTIONS */

const std::string&	Form::getName(void) const{
	return this->_name;
}

bool				Form::getSigned(void) const{
	return this->_signed;
}

int					Form::getGradeSign(void) const{
	return this->_gradeSign;
}

int					Form::getGradeExec(void) const{
	return this->_gradeExec;
}

void				Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
	return;
}
