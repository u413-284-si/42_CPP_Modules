/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_DisplayContacts.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:27:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:27:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
