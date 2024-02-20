/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:19:38 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 16:17:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

/* ====== LIBRARIES ====== */

#include "Weapon.hpp"
#include <string>
#include <iostream>

/* ====== CLASS DECLARATION ====== */
class HumanB{
	public:
				HumanB(void);
				HumanB(const std::string& name);
				~HumanB(void);

				void	attack(void);
				void	setWeapon(Weapon weapon);
	private:
				std::string	mName;
				Weapon		*mWeapon;
};

#endif
