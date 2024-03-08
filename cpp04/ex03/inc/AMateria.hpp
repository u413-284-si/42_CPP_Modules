/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:41:52 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 15:28:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class AMateria
{
	public:
				AMateria(void);
				AMateria(const std::string& type);
				AMateria(const AMateria& other);
				~AMateria(void);

				AMateria&			operator=(const AMateria& rhs);
				
				const std::string&	getType(void) const; //Returns the materia type
				virtual AMateria*	clone(void) const = 0;
				virtual void		use(ICharacter& target);

	protected:
				std::string		_type;
};

#endif
