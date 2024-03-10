/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:03 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/10 09:17:58 by sqiu             ###   ########.fr       */
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
				void			makeSound(void) const;
};

#endif
