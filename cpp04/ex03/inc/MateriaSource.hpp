/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:11:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 14:27:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/* ====== LIBRARIES ====== */

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

/* ====== DEFINITIONS ====== */

# define SRC_INV_CAPA 4

/* ====== CLASS DECLARATION ====== */

class MateriaSource : public IMateriaSource
{
	public:
				MateriaSource(void);
				MateriaSource(const MateriaSource& other);
				~MateriaSource(void);

				MateriaSource&	operator=(const MateriaSource& rhs);
				
				void		learnMateria(AMateria* materia);
				AMateria*	createMateria(const std::string& type);

	protected:
				AMateria*	_inventory[SRC_INV_CAPA];
};

#endif
