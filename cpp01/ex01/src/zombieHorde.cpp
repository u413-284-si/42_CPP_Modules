/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:27:34 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/15 17:11:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name){
	Zombie*	zombs = new Zombie[n];
	for (int x = 0; x < n; x++){
		zombs[x] = Zombie(name);
	}
	return zombs;
}
