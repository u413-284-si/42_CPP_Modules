/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:02:07 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 16:19:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

//Constructors & Destructors

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(){
	this->mName = "DI4MOND-TP";
	this->mHitPoints = FragTrap::mHP;
	this->mEnergyPoints = ScavTrap::mEP;
	this->mAttackDamage = FragTrap::mAD;
	std::cout << this->mName << ": Momma? [default]" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name",
													  FragTrap::mHP,
													  ScavTrap::mEP,
													  FragTrap::mAD){
	this->mName = name;
	std::cout << this->mName << ": Momma? [param]" << std::endl;
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
		ClapTrap::mName = rhs.ClapTrap::mName;
		this->mHitPoints = rhs.mHitPoints;
		this->mEnergyPoints = rhs.mEnergyPoints;
		this->mAttackDamage = rhs.mAttackDamage;
	}
	return *this;
}

// Member functions

void	DiamondTrap::whoAmI(void){
	std::cout << "I am " << this->mName << " and my ancestor is ";
	std::cout << ClapTrap::mName << "\n" << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}
