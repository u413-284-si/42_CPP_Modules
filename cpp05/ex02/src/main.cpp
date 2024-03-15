/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:57:29 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 11:04:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

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
	return;
}

int	main(void){
	std::cout << "\n* TEST SHRUBBERY FORM *\n" << std::endl;
	testShrubberyForm();
	return 0;
}