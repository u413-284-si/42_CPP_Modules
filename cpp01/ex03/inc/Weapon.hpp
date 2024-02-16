/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:52:25 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/16 11:05:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

/* ====== LIBRARIES ====== */

#include <string>

/* ====== CLASS DECLARATION ====== */
class Weapon{
	public:
				Weapon(void);
				~Weapon(void);

				const std::string&	getType(void);
				void				setType(std::string newType);
	private:
				std::string	mType;
};

#endif
