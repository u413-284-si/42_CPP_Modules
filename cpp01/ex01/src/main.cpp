/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:13:35 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/15 17:18:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name);

int	main(void){
	Zombie	*zombs;
	
	zombs = zombieHorde(5, "Joey");
	for (int x = 0; x < 5; x++){
		zombs[x].announce();
	}
	delete [] zombs;
	return 0;
}