/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:57:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 13:00:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

// Unit testing

void	testShrubberyForm(void){
	ShrubberyCreationForm	form("my");
	Bureaucrat				bubu("bubu", 138);

	std::cout << form << std::endl;
	bubu.executeForm(form);
	bubu.signForm(form);
	bubu.executeForm(form);
	bubu.incrGrade();
	bubu.executeForm(form);

	std::cout << "\n* Copy constructor test *\n" << std::endl;
	ShrubberyCreationForm	form02(form);
	std::cout << form02 << std::endl;
	return;
}

void	testRobotomyForm(void){
	RobotomyRequestForm	form("A199");
	Bureaucrat			bubu("bubu", 46);

	std::cout << form << std::endl;
	bubu.executeForm(form);
	bubu.signForm(form);
	bubu.executeForm(form);
	bubu.incrGrade();
	bubu.executeForm(form);
	return;
}

int	main(void){
	/* std::cout << "\n* TEST SHRUBBERY FORM *\n" << std::endl;
	testShrubberyForm(); */

	std::cout << "\n* TEST ROBOTOMY FORM *\n" << std::endl;
	testRobotomyForm();
	return 0;
}