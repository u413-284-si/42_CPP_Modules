/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:59:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/16 11:07:19 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Default Constructor
Weapon::Weapon(void){
	return;
}

// Destructor
Weapon::~Weapon(void){
	return;
}

const std::string&	Weapon::getType(void){
	std::string&	mTypeRef = this->mType;
	return mTypeRef;
}

void				Weapon::setType(std::string newType){
	this->mType = newType;
	return;
}
