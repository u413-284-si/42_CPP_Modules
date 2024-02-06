/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/06 10:54:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Constructor with initialised index to 0
PhoneBook::PhoneBook(void):mCurrentIndex(0){
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

void	PhoneBook::addContact(void){
	std::string	input[5];
	
	if (mCurrentIndex >= NUM_CONTACTS)
		mCurrentIndex = 0;
	std::cout << std::endl;
	for (int i = 0; i < 5; i++){
		parseInput(i, &input[i]);
	}
	mContactList[mCurrentIndex].setContactData(input[0], input[1], input[2], \
		input[3], input[4]);
	mCurrentIndex++;
	std::cout << "\nContact was added!" << std::endl;
	sleep(2);
	std::cout << CLRSCR;
}

void	PhoneBook::parseInput(const int field, std::string *input){
	const char	*fields[5] = {
		[0] = "first name",
		[1] = "last name",
		[2] = "nickname",
		[3] = "phone number",
		[4] = "darkest secret"
	};
	
	while (1)
	{
		std::cout << "Please enter the " << fields[field] << ":";
		std::getline(std::cin, *input);
		if (input->empty() || input->find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << RED "Input is empty, try again." RESET << std::endl;
		else if (field == 3 && input->find_first_not_of("0123456789") != std::string::npos)
			std::cout << RED "Input only digits, try again." RESET << std::endl;
		else
			break;
	}
}

void	PhoneBook::searchContact(void) const{
	
}
