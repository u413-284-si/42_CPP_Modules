/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 14:24:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class Animal{
	public:
				Animal(void);
				Animal(const std::string& typus);
				Animal(const Animal& other);
				virtual ~Animal(void);

				Animal&				operator=(const Animal& rhs);
				const std::string&	getType(void) const;
				virtual void		makeSound(void) const;

	protected:
				std::string	_type;
};

#endif
