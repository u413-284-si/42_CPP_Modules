/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:36:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/29 15:04:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <stdint.h>

/* ====== DEFINITIONS ====== */

struct Data{
	int			n;
	bool		you_good;
	char		c;
	std::string	str;
};

/* ====== CLASS DECLARATION ====== */

class Serializer{
	public:
				static uintptr_t	serialize(Data* ptr);
				static Data*		deserialize(uintptr_t raw);
				
	private:
				Serializer(void);
				Serializer(const Serializer& other);
				~Serializer(void);
				
				Serializer&	operator=(const Serializer& rhs);
};
