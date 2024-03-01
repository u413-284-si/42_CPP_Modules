/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:03:20 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 12:21:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/* ====== LIBRARIES ====== */

#include "../inc/ClapTrap.hpp"

/* ====== CLASS DECLARATION ====== */

class ScavTrap : virtual public ClapTrap{
	public:
				ScavTrap(void);
				ScavTrap(std::string name);
				ScavTrap(const ScavTrap& other);
				~ScavTrap(void);

				ScavTrap&	operator=(const ScavTrap& rhs);

				void	guardGate(void);
				void	attack(const std::string& target);
};

#endif
