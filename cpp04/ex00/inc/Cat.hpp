/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/01 18:38:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

/* ====== LIBRARIES ====== */

#include "../inc/Animal.hpp"

/* ====== CLASS DECLARATION ====== */

class Cat : public Animal{
	public:
				Cat(void);
				Cat(const Cat& other);
				~Cat(void);

				Cat&	operator=(const Cat& rhs);
				virtual void	makeSound(void) const;
};

#endif
