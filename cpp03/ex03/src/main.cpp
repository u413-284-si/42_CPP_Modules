/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:38:40 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 13:19:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int	main(void){
	DiamondTrap	a("Benediktus");
	ScavTrap	b("Iggy");
	DiamondTrap	c(a);
	ScavTrap	d;
	ClapTrap	e;

	e.attack(a.getmName());
	a.attack(b.getmName());

	// test copy constructor
	c.showStats();

	// test default constructor
	d.showStats();
	
	// test member functions
	a.takeDamage(5);
	a.beRepaired(10);
	
	// test dying without underflow
	a.takeDamage(20);
	// test incapacity
	a.attack(d.getmName());
	a.beRepaired(799);
	
	// test overflow
	b.beRepaired(MAX_UNSIGNED_INT);

	// test assignment overloading
	d = b;
	d.showStats();

	// test tiring out
	for (int i = 0; i < 9; i++)
		e.attack(d.getmName());	
	e.attack(d.getmName());
	
	return 0;
}
