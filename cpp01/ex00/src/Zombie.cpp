/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:08:14 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/15 15:18:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name):mName(name){
	announce();
	return;	
}

// Destructor
Zombie::~Zombie(void){
	std::cout << mName << ": Deeeeed" << std::endl;
}

void	Zombie::announce(void){
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
