/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/06 18:14:33 by sqiu             ###   ########.fr       */
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
				int				getLastIdea(void) const;
				void			setLastIdea(int n);
				void			setIdea(const std::string& idea, int n);

	private:
				Brain*	_brain;
				int		_lastIdea;
};

#endif
