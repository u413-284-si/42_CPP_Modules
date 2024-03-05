/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:07:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/05 16:42:29 by sqiu             ###   ########.fr       */
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
				
				void	setIdea(const std::string& idea, int n);
				void	printIdea(int n) const;
				
	private:
				std::string	_ideas[100];
};

#endif