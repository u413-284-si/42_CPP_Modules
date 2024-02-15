/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:24:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/15 15:17:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class Zombie{
	public:
				Zombie(std::string name);
				~Zombie(void);

				void	announce(void);
				Zombie*	newZombie(std::string name);
				void	randomChump(std::string name);
	private:
				std::string	mName;
};

#endif
