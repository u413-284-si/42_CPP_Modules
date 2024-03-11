/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:36:21 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 14:33:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/* CONSTRUCTORS */

Character::Character(void) : _name("Bob"){
	if (VERBOSE)
		std::cout << "[Character] default constructor called." << std::endl;
	for (int i = 0; i < INV_CAPA; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(const std::string& name) : _name(name){
	if (VERBOSE)
		std::cout << "[Character] param constructor called." << std::endl;
	for (int i = 0; i < INV_CAPA; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(const std::string& other){
	if (VERBOSE)
		std::cout << "[Character] copy constructor called." << std::endl;
	*this = other;
	return;
}

Character::~Character(void){
	if (VERBOSE)
		std::cout << "[Character] destructor called." << std::endl;
	for (int i = 0; i < INV_CAPA; i++){
			if (this->_inventory[i])
				delete this->_inventory[i];
	}
	return;
}

/* OPERATOR OVERLOADING */

Character&	Character::operator=(const Character& rhs){
	if (VERBOSE)
		std::cout << "[Character] copy assignment operator called." << std::endl;
	if (this != &rhs){
		this->_name = rhs.getName();
		for (int i = 0; i < INV_CAPA; i++){
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

/* MEMBER FUNCTIONS */

const std::string&	Character::getName(void) const{
	return this->_name;
}

void				Character::equip(AMateria* materia){
	for (int i = 0; i < INV_CAPA; i++){
		if (!this->_inventory[i]){
			this->_inventory[i] = materia;
			std::cout << this->_name << " equipped " << materia->getType();
			std::cout << " in slot " << i << std::endl;
			return;
			}
	}
	/* std::cout << this->_name << " can't equip " << m->getType();
	std::cout << ". Inventory full!" << std::endl; */
	return;
}

void				Character::unequip(int idx){
	if (idx >= 0 && idx < INV_CAPA && this->_inventory[idx]){
		std::cout << this->_name << " throws " << this->_inventory[idx]->getType();
		std::cout << " from slot " << idx << " to the ground!" << std::endl;
		this->_inventory[idx] = NULL;
	}
	return;
}

void				Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < INV_CAPA && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	return;
}
