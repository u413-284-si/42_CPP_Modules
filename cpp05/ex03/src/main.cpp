/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:57:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 20:06:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

// Unit testing

void	testIntern(void){
	Bureaucrat				bubu("bubu", 6);
	Intern					mumu;
	AForm*					fPtr = NULL;

	try{
		fPtr = mumu.makeForm("wrongform", "bubus bamboozle");
		std::cout << *fPtr << std::endl;
		bubu.executeForm(*fPtr);
		bubu.signForm(*fPtr);
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	try{
		fPtr = mumu.makeForm("shrubbery creation", "bubus bamboozle");
		std::cout << *fPtr << std::endl;
		bubu.executeForm(*fPtr);
		bubu.signForm(*fPtr);
		bubu.executeForm(*fPtr);
		delete fPtr;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		fPtr = mumu.makeForm("robotomy request", "bubus bamboozle");
		std::cout << *fPtr << std::endl;
		bubu.executeForm(*fPtr);
		bubu.signForm(*fPtr);
		bubu.executeForm(*fPtr);
		delete fPtr;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	try{
		fPtr = mumu.makeForm("presidential pardon", "bubus bamboozle");
		std::cout << *fPtr << std::endl;
		bubu.executeForm(*fPtr);
		bubu.signForm(*fPtr);
		bubu.executeForm(*fPtr);
		bubu.incrGrade();
		bubu.executeForm(*fPtr);
		delete fPtr;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

int	main(void){
	std::cout << "\n* TEST INTERN *\n" << std::endl;
	testIntern();
	return 0;
}
