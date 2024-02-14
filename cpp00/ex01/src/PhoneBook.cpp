/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:28:04 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Constructor with initialised index to 0
PhoneBook::PhoneBook(void):mCurrentIndex(0), 
						   mNumContacts(0){
	return;
}

// Destructor
PhoneBook::~PhoneBook(void){
	return;
}

void	PhoneBook::start(void){
	std::cout << CYAN "\n\t\tPHONEBOOK OF MYSTERIES\n" RESET << std::endl;
}

void	PhoneBook::processInput(void){
	std::string	input;
	
	while (1)
	{
		promptCommands();
		std::cin >> input;
		std::cin.ignore();
		if (input == "ADD")
			addContact();
		else if (input == "SEARCH")
			searchContact();
		else if (input == "EXIT")
			break;
		else
		{
			std::cout << BOLD RED"\nInvalid input, you moron ʕ•́ᴥ•̀ʔっ\n" RESET << std::endl;
			sleep(2);
			std::cout << CLRSCR;
		}
	}
}

void	PhoneBook::promptCommands(void) const{
	std::cout << "Please enter one of the following commands:\n" << std::endl;
	std::cout << "ADD:\tadd a new contact to the phonebook" << std::endl;
	std::cout << "SEARCH:\tshow all saved contacts and their details" << std::endl;
	std::cout << "EXIT:\texit the phonebook\n" << std::endl;
}
