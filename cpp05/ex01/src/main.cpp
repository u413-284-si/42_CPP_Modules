/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:57:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/14 18:02:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

// Boundary value testing

void	testSignHighException(void){
	Form	f("test", -1, 8);
	return;
}

void	testSignLowException(void){
	Form	f("test", 151, 9);
	return;
}

void	testExecHighException(void){
	Form	f("test", 4, -1);
	return;
}

void	testExecLowException(void){
	Form	f("test", 8, 151);
	return;
}

// Unit testing

void	testFormSigning(void){
	Form		form("test", 7, 8);
	Bureaucrat	bubu("bubu", 8);

	std::cout << form << std::endl;
	bubu.signForm(form);
	bubu.incrGrade();
	bubu.signForm(form);
	std::cout << form << std::endl;
	return;
}

int	main(void){
	std::cout << "\n* TEST SIGN HIGH EXCEPTION *\n" << std::endl;
	try{
		testSignHighException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST SIGN LOW EXCEPTION *\n" << std::endl;
	try{
		testSignLowException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST EXEC HIGH EXCEPTION *\n" << std::endl;
	try{
		testExecHighException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST EXEC LOW EXCEPTION *\n" << std::endl;
	try{
		testExecLowException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST FORM SIGNING*\n" << std::endl;
	testFormSigning();
	return 0;
}
