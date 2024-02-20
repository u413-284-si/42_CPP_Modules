/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:27 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 15:04:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(void){
	return;
}

// Destructor
HumanB::~HumanB(void){
	return;
}

void	HumanB::attack(void){
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}