/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:34:33 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/28 15:16:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class ClapTrap{
	public:
				ClapTrap(void);
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap& other);
				~ClapTrap(void);

				ClapTrap&	operator=(const ClapTrap& rhs);
				
				void		attack(const std::string& target);
				void		takeDamage(unsigned int amount);
				void		beRepaired(unsigned int amount);
				void		showStats(void) const;

	private:
				std::string		mName;
				unsigned int	mHitPoints;
				unsigned int	mEnergyPoints;
				unsigned int	mAttackDamage;

				bool		happy(void) const;
};

#endif
