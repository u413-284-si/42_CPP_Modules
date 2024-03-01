/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:15:31 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 13:25:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

//Constructors & Destructors

ClapTrap::ClapTrap(void) :	mName("CL4P-TP"),
							mHitPoints(10),
							mEnergyPoints(10), 
							mAttackDamage(0){
	std::cout << "CL4P-TP at your service!" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) :	mName(name),
										mHitPoints(10),
										mEnergyPoints(10),
										mAttackDamage(0){
	std::cout << this->mName << " at your service!" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
	std::cout << "Let the clone wars begin!" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void){
	std::cout << this->mName << " signing off..." << std::endl;
	return;
}

// Operator overloading

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs){
	if (this != &rhs){
		this->mName = rhs.mName;
		this->mHitPoints = rhs.mHitPoints;
		this->mEnergyPoints = rhs.mEnergyPoints;
		this->mAttackDamage = rhs.mAttackDamage;
	}
	return *this;
}

// Member functions

bool	ClapTrap::happy(void) const{
	if (this->mHitPoints > 0 && this->mEnergyPoints > 0)
		return true;
	else if (this->mHitPoints == 0){
		std::cout << this->mName << " can't cause dead." << std::endl;
		return false;
	}
	else if (this->mEnergyPoints == 0)
		std::cout << this->mName << " can't cause sooo tired." << std::endl;
	return false;
}

void	ClapTrap::showStats(void) const{
	std::cout << this->mName << " stats:\n";
	std::cout << this->mHitPoints << " HP\n";
	std::cout << this->mEnergyPoints << " EP\n" << std::endl;
	return;
}

void	ClapTrap::attack(const std::string& target){
	if (this->happy()){
		std::cout << "ClapTrap " << this->mName << " attacks " << target ;
		std::cout << " causing " << this->mAttackDamage << " points of damage!";
		std::cout << std::endl;
		this->mEnergyPoints--;
	}
	this->showStats();
	return;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << this->mName << " takes " << amount << " damage!" << std::endl;
	if (amount > this->mHitPoints)
		this->mHitPoints = 0;
	else
		this->mHitPoints -= amount;
	if (this->mHitPoints == 0)
		std::cout << "[ " << this->mName << " ]: Darkness engulfs me..." << std::endl;
	this->showStats();
	return;
}

void	ClapTrap::beRepaired(unsigned int amount){
	unsigned long	tmp;
	
	if (this->happy()){
		std::cout << this->mName << " juicing up by " << amount << " HP!" << std::endl;
		tmp = (unsigned long)this->mHitPoints + (unsigned long)amount;
		if (tmp > MAX_UNSIGNED_INT)
			this->mHitPoints = MAX_UNSIGNED_INT;
		else
			this->mHitPoints += amount;
		this->mEnergyPoints--;
	}
	this->showStats();
	return;
}

const std::string&	ClapTrap::getmName(void) const{
	return this->mName;
}
