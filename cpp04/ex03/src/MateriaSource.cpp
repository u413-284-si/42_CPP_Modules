/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:20:48 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 14:45:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/* CONSTRUCTORS */

MateriaSource::MateriaSource(void){
	if (VERBOSE)
		std::cout << "[MateriaSource] default constructor called." << std::endl;
	for (int i = 0; i < SRC_INV_CAPA; i++)
		this->_inventory[i] = NULL;
	return;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	if (VERBOSE)
		std::cout << "[MateriaSource] copy constructor called." << std::endl;
	*this = other;
	return;
}

MateriaSource::~MateriaSource(void){
	if (VERBOSE)
		std::cout << "[MateriaSource] destructor called." << std::endl;
	for (int i = 0; i < SRC_INV_CAPA; i++){
			if (this->_inventory[i])
				delete this->_inventory[i];
	}
	return;
}

/* OPERATOR OVERLOADING */

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs){
	if (VERBOSE)
		std::cout << "[MateriaSource] copy assignment operator called." << std::endl;
	if (this != &rhs){
		for (int i = 0; i < SRC_INV_CAPA; i++){
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

void	MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < SRC_INV_CAPA; i++){
		if (!this->_inventory[i]){
			this->_inventory[i] = materia;
			std::cout << "Stored " << materia->getType();
			std::cout << " in slot " << i << std::endl;
			return;
			}
	}
	std::cout << "Can't store " << materia->getType();
	std::cout << ". Inventory full!" << std::endl;
	return;
}

AMateria*	MateriaSource::createMateria(const std::string& type){
	for (int i = 0; i < SRC_INV_CAPA; i++){
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	std::cout << "Can't create " << type;
	std::cout << ". This type is not learned!" << std::endl;
	return NULL;
}
