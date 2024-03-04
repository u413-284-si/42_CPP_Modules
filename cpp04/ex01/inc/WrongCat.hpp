/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 14:06:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

/* ====== LIBRARIES ====== */

#include "../inc/WrongAnimal.hpp"

/* ====== CLASS DECLARATION ====== */

class WrongCat : public WrongAnimal{
	public:
				WrongCat(void);
				WrongCat(const WrongCat& other);
				~WrongCat(void);

				WrongCat&		operator=(const WrongCat& rhs);
				virtual void	makeSound(void) const;
};

#endif
