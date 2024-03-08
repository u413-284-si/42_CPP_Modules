/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 11:56:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

/* ====== LIBRARIES ====== */

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

/* ====== CLASS DECLARATION ====== */

class Cat : public Animal{
	public:
				Cat(void);
				Cat(const Cat& other);
				~Cat(void);

				Cat&	operator=(const Cat& rhs);
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
