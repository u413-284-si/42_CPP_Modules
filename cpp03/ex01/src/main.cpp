/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:38:40 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 12:11:13 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void){
	ScavTrap	a("Benediktus");
	ScavTrap	b("Iggy");
	ScavTrap	c(a);
	ScavTrap	d;

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
	for (int i = 0; i < 50; i++)
		c.attack(d.getmName());	
	c.attack(d.getmName());
	
	return 0;
}
