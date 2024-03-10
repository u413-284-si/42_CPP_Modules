/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/10 09:17:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class WrongAnimal{
	public:
				WrongAnimal(void);
				WrongAnimal(const std::string& typus);
				WrongAnimal(const WrongAnimal& other);
				virtual ~WrongAnimal(void);

				WrongAnimal&		operator=(const WrongAnimal& rhs);
				const std::string&	getType(void) const;
				void				makeSound(void) const;

	protected:
				std::string	_type;
};

#endif
