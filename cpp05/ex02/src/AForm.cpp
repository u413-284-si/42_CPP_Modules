/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:43:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/14 17:47:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

/* CONSTRUCTORS */

AForm::AForm(void) : _name("undefined"), _signed(false), _gradeSign(10), _gradeExec(20){
	if (VERBOSE)
		std::cout << "[AForm] Default constructor called." << std::endl;
	return;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) :	_name(name),
																		_signed(false),
																		_gradeSign(gradeSign),
																		_gradeExec(gradeExec){
	if (VERBOSE)
		std::cout << "[AForm] Param constructor called." << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	return;
}

AForm::AForm(const AForm& other) :	_name(other.getName()),
									_signed(other.getSigned()),
									_gradeSign(other.getGradeSign()),
									_gradeExec(other.getGradeExec()){
	if (VERBOSE)
		std::cout << "[AForm] Copy constructor called." << std::endl;
	return;
}

AForm::~AForm(void){
	if (VERBOSE)
		std::cout << "[AForm] Destructor called." << std::endl;
	return;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "form exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "form exception: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "form exception: not signed";
}

/* OPERATOR OVERLOADING */

AForm&		AForm::operator=(const AForm& rhs){
	if (VERBOSE)
		std::cout << "[AForm] Copy assignment operator called." << std::endl;
	if (this != &rhs){
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const AForm& f){
	os << f.getName() << " form min. sign grade " << f.getGradeSign() << ".\n";
	os << f.getName() << " form min. exec grade " << f.getGradeExec() << ".\n";
	os << f.getName() << " form signed: " << f.getSigned() << ".";
	return os;
}

/* MEMBER FUNCTIONS */

const std::string&	AForm::getName(void) const{
	return this->_name;
}

bool				AForm::getSigned(void) const{
	return this->_signed;
}

int					AForm::getGradeSign(void) const{
	return this->_gradeSign;
}

int					AForm::getGradeExec(void) const{
	return this->_gradeExec;
}

void				AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
	return;
}

void				AForm::checkExec(const Bureaucrat& executor) const{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	return;
}
