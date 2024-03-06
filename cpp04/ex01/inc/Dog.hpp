/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/06 18:04:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

/* ====== LIBRARIES ====== */

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

/* ====== CLASS DECLARATION ====== */

class Dog : public Animal{
	public:
				Dog(void);
				Dog(const Dog& other);
				~Dog(void);

				Dog&	operator=(const Dog& rhs);
				virtual void	makeSound(void) const;
				void			printIdeas(void) const;
				int				getCurIdea(void) const;

	private:
				Brain*	_brain;
				int		_curIdea;
};

#endif
