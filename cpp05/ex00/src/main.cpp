/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:57:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/13 00:26:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

void	testNoException(void){
	Bureaucrat	bibi("bibi", 3);
	
	std::cout << bibi << std::endl;
	bibi.incrGrade();
	std::cout << bibi << std::endl;
	bibi.decrGrade();
	std::cout << bibi << std::endl;
	return;	
}

// Boundary value testing

void	testConstructorHighException(void){
	Bureaucrat	bubu("bubu", -1);
	return;
}

void	testConstructorLowException(void){
	Bureaucrat	bubu("bubu", 151);
	return;
}

// Unit testing

void	testIncrementHighException(void){
	Bureaucrat	bubu("bubu", 1);

	bubu.incrGrade();
	return;
}

void	testDecrementLowException(void){
	Bureaucrat	bubu("bubu", 150);

	bubu.decrGrade();
	return;
}

int	main(void){
	std::cout << "\n* TEST NO EXCEPTION *\n" << std::endl;
	try{
		testNoException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST CONSTRUCTOR HIGH EXCEPTION *\n" << std::endl;
	try{
		testConstructorHighException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST CONSTRUCTOR LOW EXCEPTION *\n" << std::endl;
	try{
		testConstructorLowException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST INCREMENT HIGH EXCEPTION *\n" << std::endl;
	try{
		testIncrementHighException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n* TEST DECREMENT LOW EXCEPTION *\n" << std::endl;
	try{
		testDecrementLowException();
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}