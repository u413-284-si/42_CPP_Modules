/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:19:38 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 15:04:25 by sqiu             ###   ########.fr       */
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
				~HumanB(void);

				void	attack(void);
	private:
				Weapon		mWeapon;
				std::string	mName;
};

#endif
