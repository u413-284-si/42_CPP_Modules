/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:02:07 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 13:23:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

//Constructors & Destructors

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(){
	this->mName = "DI4MOND-TP";
	this->mHitPoints = FragTrap::mHitPoints;
	this->mEnergyPoints = ScavTrap::mEnergyPoints;
	this->mAttackDamage = FragTrap::mAttackDamage;
	std::cout << this->mName << ": Momma?" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) :	ClapTrap(name + "_clap_name"),
												ScavTrap(name),
												FragTrap(name){
	this->mName = name;
	this->mHitPoints = FragTrap::mHitPoints;
	this->mEnergyPoints = ScavTrap::mEnergyPoints;
	this->mAttackDamage = FragTrap::mAttackDamage;
	std::cout << this->mName << ": Momma?" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :	ClapTrap(other),
														ScavTrap(other),
														FragTrap(other){
	*this = other;
	std::cout << this->mName << ": I am Groot";
	std::cout << std::endl;
	return;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << this->mName << ": Bot down." << std::endl;
	return;
}

// Operator overloading

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs){
	if (this != &rhs){
		this->mName = rhs.mName;
		this->mHitPoints = rhs.mHitPoints;
		this->mEnergyPoints = rhs.mEnergyPoints;
		this->mAttackDamage = rhs.mAttackDamage;
	}
	return *this;
}

// Member functions

void	DiamondTrap::whoAmI(void){
	std::cout << "I am " << this->mName << "and my ancestor is";
	std::cout << ClapTrap::mName << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}