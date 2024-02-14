/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_SearchContact.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:57 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:25:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::searchContact(void) const{
	if (mNumContacts == 0)
		std::cout << BOLD "\nNo contacts available. Please add contacts first." RESET << std::endl;
	else {
		displayContacts();
		promptContact();
	}
	sleep(5);
	std::cout << CLRSCR;
	return;
}

void	PhoneBook::promptContact(void) const{
	std::string	input;
	char		index;
	int			i;
	
	std::cout << "\nChoose the contact to be displayed by entering the index: " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		std::cout << RED "Input is empty, try again." RESET << std::endl;
	else if (input.length() > 1)
		std::cout << RED "Only one character is accepted." RESET << std::endl;
	else {	
		index = input[0];
		i = atoi(&index);
		if (!isdigit(index))
			std::cout << RED "The index can only be numerical. By definition. Dipshit." RESET << std::endl;
		else if ( i > mNumContacts - 1)
			std::cout << RED "Index is out of bounds. No contact available." RESET << std::endl;
		else
			mContactList[i].printContactData();
	}
}
