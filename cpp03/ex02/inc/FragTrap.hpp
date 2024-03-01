/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:03:20 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 12:22:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/* ====== LIBRARIES ====== */

#include "../inc/ClapTrap.hpp"

/* ====== CLASS DECLARATION ====== */

class FragTrap : virtual public ClapTrap{
	public:
				FragTrap(void);
				FragTrap(std::string name);
				FragTrap(const FragTrap& other);
				~FragTrap(void);

				FragTrap&	operator=(const FragTrap& rhs);

				void	highFivesGuys(void);
};

#endif
