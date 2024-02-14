/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:15:20 by sqiu             ###   ########.fr       */
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

void	PhoneBook::displayContacts(void) const{
	displayTitleRow();
	for (int i = 0; i < mNumContacts; i++){
		displayContactRow(i);
	}
}

void	PhoneBook::displayTitleRow(void) const{
	createColumn(0);
	std::cout << "Index";
	createColumn(0);
	std::cout << "First name";
	createColumn(0);
	std::cout << "Last name";
	createColumn(0);
	std::cout << "Nickname";
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayContactRow(const int i) const{
	int 		extra_width = 0;
	std::string	data;
	
	createColumn(extra_width);
	std::cout << i;
	
	data = truncateData(mContactList[i].getFirstName(), &extra_width);
	createColumn(extra_width);
	std::cout << data;
	
	extra_width = 0;
	data = truncateData(mContactList[i].getLastName(), &extra_width);
	createColumn(extra_width);
	std::cout << data;
	
	extra_width = 0;
	data = truncateData(mContactList[i].getNickname(), &extra_width);
	createColumn(extra_width);
	std::cout << data;
	
	std::cout << "|" << std::endl;
}

std::string PhoneBook::truncateData(std::string data, int *extra) const{
	size_t	len = 0;
	int		bytes;
	int		overshoot = 0;
	
    for (size_t i = 0; i < data.length();) {
        bytes = 1;
        if ((data[i] & 0xf8) == 0xf0) // checking whether the current byte is the start of a 4-byte UTF-8 character
			bytes = 4;
        else if ((data[i] & 0xf0) == 0xe0) // checking whether the current byte is the start of a 3-byte UTF-8 character
			bytes = 3;
        else if ((data[i] & 0xe0) == 0xc0) // checking whether the current byte is the start of a 2-byte UTF-8 character
			bytes = 2;
		if (bytes > 1)
			overshoot += bytes - 1;
        if ((i + bytes) > data.length())
            bytes = 1;
        i += bytes;
        len++;
        if (len == COLUMN_WIDTH && i < data.length()){
            data[i - bytes] = '.';
            data.resize(i - bytes + 1);
            break;
        }
    }
	if (overshoot > 0 && len < COLUMN_WIDTH)
		*extra = overshoot;
	return data;
}

void	PhoneBook::createColumn(int extra_width) const{
	if (extra_width > 0)
			std::cout << "|" << std::setw(COLUMN_WIDTH + extra_width);
	else
		std::cout << "|" << std::setw(COLUMN_WIDTH);
}
