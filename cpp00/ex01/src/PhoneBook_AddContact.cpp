/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_AddContact.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:23:19 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:24:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(void){
	std::string	input[5];
	
	if (mCurrentIndex >= MAX_CONTACTS)
		mCurrentIndex = 0;
	if (mNumContacts < MAX_CONTACTS)
		mNumContacts++;
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
		std::cout << "Please enter the " << fields[field] << ": ";
		std::getline(std::cin, *input);
		if (input->empty() || input->find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << RED "Input is empty, try again." RESET << std::endl;
		else if (field == 3 && input->find_first_not_of("0123456789") != std::string::npos)
			std::cout << RED "Input only digits, try again." RESET << std::endl;
		else
			break;
	}
}
