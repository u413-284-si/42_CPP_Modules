/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:35:33 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 15:03:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(void){
	return;
}

// Destructor
HumanA::~HumanA(void){
	return;
}

void	HumanA::attack(void){
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}
