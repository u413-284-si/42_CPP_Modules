/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/05 18:06:46 by sqiu             ###   ########.fr       */
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
	std::cout << "PHONEBOOK OF MYSTERIES" << std::endl << std::endl;
}

void	PhoneBook::processInput(void){
	std::string	input;
	
	while (1)
	{
		promptCommands();
		std::cin >> input;
		if (input == "ADD")
			addContact();
		else if (input == "SEARCH")
			searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid input, you moron" << std::endl;
	}
}

void	PhoneBook::promptCommands(void) const{
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "ADD: add a new contact to the phonebook" << std::endl;
	std::cout << "SEARCH: show all saved contacts and their details" << std::endl;
	std::cout << "EXIT: exit the phonebook" << std::endl;
}

void	PhoneBook::addContact(void){
	std::string	input[5];
	
	if (mCurrentIndex >= NUM_CONTACTS)
		mCurrentIndex = 0;
	for (int i = 0; i < 5; i++){
		parseInput(i, input[i]);
	}
	mContactList[mCurrentIndex].setContactData(input[0], input[1], input[2], \
		input[3], input[4]);
	mCurrentIndex++;
}

void	PhoneBook::parseInput(const Contact::eFields field, std::string input){
	while (1)
	{
		std::cout << "Please enter " << field << ":";
		std::cin >> input;
		if (input.empty() || input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << "Input is empty, try again." << std::endl;
		else if (field == 3 && !all_of(input.begin(), input.end(), ::isdigit))
			std::cout << "Input only digits, try again." << std::endl;
		else
			break;
	}	
}
