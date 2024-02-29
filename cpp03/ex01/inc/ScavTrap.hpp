/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:03:20 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/29 15:08:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/* ====== LIBRARIES ====== */

/* ====== CLASS DECLARATION ====== */

class ScavTrap{
	public:
				ScavTrap(void);
				ScavTrap(const ScavTrap&);
				~ScavTrap(void);

				ScavTrap&	operator=(const ScavTrap&);

				void	guardGate(void);

	private:
	
};

#endif
