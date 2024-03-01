/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:38:40 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 15:13:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int	main(void){
	DiamondTrap	a("Benediktus");

	a.whoAmI();
	a.attack("you");
	a.guardGate();
	a.highFivesGuys();
	a.beRepaired(3423);
	a.takeDamage(10000);
	
	DiamondTrap b;
	return 0;
}
