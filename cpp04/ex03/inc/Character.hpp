/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:22:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 16:39:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* ====== LIBRARIES ====== */

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

/* ====== DEFINITIONS ====== */

# define INV_CAPA 4

/* ====== CLASS DECLARATION ====== */

class Character : public ICharacter{
	public:
				Character(void);
				Character(const std::string& name);
				Character(const Character& other);
				~Character(void);

				Character&			operator=(const Character& rhs);
				
				const std::string&	getName(void) const;
				void				equip(AMateria* m);
				void				unequip(int idx);
				void				use(int idx, ICharacter& target);

	protected:
				AMateria*	_inventory[INV_CAPA];
				std::string	_name;	
};

#endif
