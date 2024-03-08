/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:45:49 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 16:33:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

/* ====== LIBRARIES ====== */

#include <iostream>
#include "AMateria.hpp"

/* ====== CLASS DECLARATION ====== */

class Ice : public AMateria{
	public:
				Ice(void);
				Ice(const Ice& other);
				~Ice(void);

				Ice&				operator=(const Ice& rhs);
				
				AMateria*	clone(void) const;
				void		use(ICharacter& target);
};

#endif
