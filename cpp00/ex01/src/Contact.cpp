/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:13:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/11 22:59:22 by sqiu             ###   ########.fr       */
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

void	Contact::printContactData(void) const{
	
}

void	Contact::setFirstName(const std::string& firstName){
	this->mFirstName = firstName;
}

void	Contact::setLastName(const std::string& lastName){
	this->mLastName = lastName;
}

void	Contact::setNickname(const std::string& nickname){
	this->mNickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber){
	this->mPhoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret){
	this->mDarkestSecret = darkestSecret;
}

void	Contact::setContactData(const std::string& firstName, \
								const std::string& lastName, \
								const std::string& nickname, \
								const std::string& phoneNumber, \
								const std::string& darkestSecret){
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setNickname(nickname);
	this->setPhoneNumber(phoneNumber);
	this->setDarkestSecret(darkestSecret);
}
