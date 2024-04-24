/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:43:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/24 15:48:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <vector>

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

class PmergeMe{
	public:
				template <typename Iterator> 
				class GroupIterator{
					public:
								GroupIterator(void);
								GroupIterator(Iterator it, std::size_t size);
								GroupIterator(const GroupIterator& other);
								~GroupIterator(void);

								GroupIterator&	operator=(const GroupIterator& rhs);

								Iterator	getIterator(void) const;
								std::size_t	getSize(void) const;
					private:
								Iterator	_it;
								std::size_t	_size;	
				};

	private:
				
			

};
