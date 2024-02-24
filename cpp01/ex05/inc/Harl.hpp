/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:07:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/24 14:13:12 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== TYPEDEFS ====== */

typedef void	(Harl::*pointerMF)(void) const;

/* ====== CLASS DECLARATION ====== */

class Harl{
	public:
				Harl(void);
				~Harl(void);
				
				void	complain(std::string level);
	private:
				pointerMF	mode[4];
				
				void	debug(void);
				void	info(void);
				void	warning(void);
				void	error(void);

				int		convertLevel(const std::string level);
};

#endif
