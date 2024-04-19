/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:06:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 14:40:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <stack>
#include <stdexcept>
#include <limits>

/* ====== DEFINITIONS ====== */

# define VERBOSE 0

/* ====== CLASS DECLARATION ====== */

class RPN{
	public:
				RPN(void);
				RPN(const RPN& other);
				~RPN(void);
				
				RPN&	operator=(const RPN& rhs);

				void	parseInput(const std::string input);
				int		getResult(void);
	private:
				std::stack<int>	_st;
				
				void	doTheMaths(const std::string::const_iterator& cit);

};
