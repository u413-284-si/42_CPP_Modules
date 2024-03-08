/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 12:46:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class AAnimal{
	public:
				AAnimal(void);
				AAnimal(const std::string& typus);
				AAnimal(const AAnimal& other);
				virtual ~AAnimal(void);

				AAnimal&			operator=(const AAnimal& rhs);
				const std::string&	getType(void) const;
				virtual void		makeSound(void) const = 0;

	protected:
				std::string	_type;
};

#endif
