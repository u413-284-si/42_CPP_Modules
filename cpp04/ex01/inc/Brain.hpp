/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:07:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/04 17:13:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class Brain{
	public:
				Brain(void);
				Brain(const Brain& other);
				~Brain(void);

				Brain&	operator=(const Brain& rhs);

				std::string	ideas[100];
};

#endif