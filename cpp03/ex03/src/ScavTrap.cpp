/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:14:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 15:13:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

//Constructors & Destructors

ScavTrap::ScavTrap(void) : ClapTrap(){
	this->mHitPoints = 100;
	this->mEnergyPoints = 50;
	this->mAttackDamage = 20;
	std::cout << this->mName << ": Bugalooshrimp it is!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->mHitPoints = 100;
	this->mEnergyPoints = 50;
	this->mAttackDamage = 20;
	std::cout << this->mName << ": Bugalooshrimp it is!" << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	*this = other;
	std::cout << this->mName << ": Cloned Bugalooshrimp it is!" << std::endl;
	return;
}

// Destructor of base class ClapTrap is automatically called by Destructor
// of derived class Scav Trap
ScavTrap::~ScavTrap(void){
	std::cout << this->mName << ": adieu du schnöde Welt" << std::endl;
	return;
}

// Operator overloading

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs){
	if (this != &rhs){
		this->mName = rhs.mName;
		this->mHitPoints = rhs.mHitPoints;
		this->mEnergyPoints = rhs.mEnergyPoints;
		this->mAttackDamage = rhs.mAttackDamage;
	}
	return *this;
}

// Member functions

void	ScavTrap::guardGate(void){
	std::cout << this->mName << ": Gate keeping mode activated!!\n" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (this->happy()){
		std::cout << "ScavTrap " << this->mName << " attacks " << target ;
		std::cout << " causing " << this->mAttackDamage << " points of damage!";
		std::cout << std::endl;
		this->mEnergyPoints--;
	}
	this->showStats();
	return;
}
