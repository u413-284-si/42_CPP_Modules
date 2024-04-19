/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:06:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 15:49:16 by sqiu             ###   ########.fr       */
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

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"    
#define GREEN   "\033[32m"    
#define YELLOW  "\033[33m"    
#define BLUE    "\033[34m"    
#define MAGENTA "\033[35m"    
#define CYAN    "\033[36m"    
#define WHITE   "\033[37m"  

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
