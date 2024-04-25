/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:43:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/24 16:26:32 by sqiu             ###   ########.fr       */
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
								// Constructors & Destructor
								GroupIterator(void);
								GroupIterator(Iterator it, std::size_t size);
								GroupIterator(const GroupIterator& other);
								~GroupIterator(void);

								GroupIterator&	operator=(const GroupIterator& rhs);

								// Aliases
								typedef std::random_access_iterator_tag iterator_category;
								typedef std::iterator_traits<Iterator>::value_type value_type;
								typedef std::iterator_traits<Iterator>::difference_type difference_type;
								typedef std::iterator_traits<Iterator>::pointer pointer;
								typedef std::iterator_traits<Iterator>::reference reference;

								// Member access
								Iterator	getIterator(void) const;
								std::size_t	getSize(void) const;

								// Element access
								reference	operator*(void) const;
								pointer		operator->(void) const;

								// Increment/decrement operators
								GroupIterator&	operator++(void);
								GroupIterator	operator++(int);
								GroupIterator&	operator--(void);
								GroupIterator	operator--(int);
								GroupIterator&	operator+=(std::size_t increment);
								GroupIterator&	operator-=(std::size_t increment);

					private:
								Iterator	_it;
								std::size_t	_size;	
				};

				template<typename Iterator1, typename Iterator2>
				void	iter_swap(GroupIterator<Iterator1> lhs, GroupIterator<Iterator2> rhs);

				// Comparison operators

	private:
				
			

};
