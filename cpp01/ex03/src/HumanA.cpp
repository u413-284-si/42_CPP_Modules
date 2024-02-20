/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:35:33 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 16:16:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor with initialised attributes
HumanA::HumanA(const std::string& name, Weapon& weapon) : mName(name),
													mWeapon(weapon){
	return;
}

// Destructor
HumanA::~HumanA(void){
	return;
}

void	HumanA::attack(void) const{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}
