/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:20 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 14:11:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include "AMateria.hpp"

/* ====== CLASS DECLARATION ====== */

class IMateriaSource
{
	public:
				virtual ~IMateriaSource() {}
				
				virtual void		learnMateria(AMateria*) = 0;
				virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
