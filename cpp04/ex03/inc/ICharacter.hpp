/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:15:59 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 15:31:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include "AMateria.hpp"

/* ====== CLASS DECLARATION ====== */
class AMateria;

class ICharacter{
	public:
			virtual ~ICharacter(void) {}
			
			virtual const std::string&	getName(void) const = 0;
			virtual void				equip(AMateria* m) = 0;
			virtual void				unequip(int idx) = 0;
			virtual void				use(int idx, ICharacter& target) = 0;
			virtual AMateria*			getMateria(int idx) const = 0;
};

#endif
