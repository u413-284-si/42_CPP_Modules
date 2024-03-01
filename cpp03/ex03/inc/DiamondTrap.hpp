/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:03:20 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 13:00:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/* ====== LIBRARIES ====== */

#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

/* ====== CLASS DECLARATION ====== */

class DiamondTrap : public ScavTrap, public FragTrap{
	public:
				DiamondTrap(void);
				DiamondTrap(std::string name);
				DiamondTrap(const DiamondTrap& other);
				~DiamondTrap(void);

				DiamondTrap&	operator=(const DiamondTrap& rhs);

				void	whoAmI(void);
				void	attack(const std::string& target);
	private:
				std::string	mName;
};

#endif
