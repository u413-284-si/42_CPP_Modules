/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:14:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 15:13:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

//Constructors & Destructors

FragTrap::FragTrap(void) : ClapTrap(){
	this->mHitPoints = 100;
	this->mEnergyPoints = 100;
	this->mAttackDamage = 30;
	std::cout << this->mName << ": Ciao bello!" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->mHitPoints = 100;
	this->mEnergyPoints = 100;
	this->mAttackDamage = 30;
	std::cout << this->mName << ": Ciao bello!" << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	*this = other;
	std::cout << this->mName << ": Ciao belli!";
	std::cout << std::endl;
	return;
}

// Destructor of base class ClapTrap is automatically called by Destructor
// of derived class Frag Trap
FragTrap::~FragTrap(void){
	std::cout << this->mName << ": mamma mia porca madonna" << std::endl;
	return;
}

// Operator overloading

FragTrap&	FragTrap::operator=(const FragTrap& rhs){
	if (this != &rhs){
		this->mName = rhs.mName;
		this->mHitPoints = rhs.mHitPoints;
		this->mEnergyPoints = rhs.mEnergyPoints;
		this->mAttackDamage = rhs.mAttackDamage;
	}
	return *this;
}

// Member functions

void	FragTrap::highFivesGuys(void){
	std::cout << this->mName << ": Who wants to High Five!!!\n" << std::endl;
}
