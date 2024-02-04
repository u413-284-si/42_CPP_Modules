/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:13:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/04 17:00:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(void){
	return;
}

// Destructor
Contact::~Contact(void){
	return;
}

std::string	Contact::getFirstName(void) const{
	return this->mFirstName;
}

std::string	Contact::getLastName(void) const{
	return this->mLastName;
}

std::string	Contact::getNickname(void) const{
	return this->mNickname;
}

std::string	Contact::getPhoneNumber(void) const{
	return this->mPhoneNumber;
}

std::string	Contact::getDarkestSecret(void) const{
	return this->mDarkestSecret;
}

void	Contact::setFirstName(std::string firstName){
	this->mFirstName = firstName;
}

void	Contact::setLastName(std::string lastName){
	this->mLastName = lastName;
}

void	Contact::setNickname(std::string nickname){
	this->mNickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber){
	this->mPhoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret){
	this->mDarkestSecret = darkestSecret;
}

void	Contact::setContactData(std::string firstName, \
								std::string lastName, \
								std::string nickname, \
								std::string phoneNumber, \
								std::string darkestSecret){
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setNickname(nickname);
	this->setPhoneNumber(phoneNumber);
	this->setDarkestSecret(darkestSecret);
}
