/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:45:49 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 16:34:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

/* ====== LIBRARIES ====== */

#include <iostream>
#include "AMateria.hpp"

/* ====== CLASS DECLARATION ====== */

class Cure : public AMateria{
	public:
				Cure(void);
				Cure(const Cure& other);
				~Cure(void);

				Cure&				operator=(const Cure& rhs);
				
				AMateria*	clone(void) const;
				void		use(ICharacter& target);
};

#endif
