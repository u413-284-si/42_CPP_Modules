/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:07:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/24 12:24:36 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class Harl{
	public:
				Harl(void);
				~Harl(void);
				
				void	complain(std::string level);
	private:
				void	debug(void);
				void	info(void);
				void	warning(void);
				void	error(void);
};

#endif
