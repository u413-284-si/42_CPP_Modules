/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:19:41 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/20 16:16:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

/* ====== LIBRARIES ====== */

#include "Weapon.hpp"
#include <string>
#include <iostream>

/* ====== CLASS DECLARATION ====== */
class HumanA{
	public:
				HumanA(const std::string& name, Weapon& weapon);
				~HumanA(void);

				void	attack(void) const;
	private:
				std::string	mName;
				Weapon&		mWeapon;
};

#endif
