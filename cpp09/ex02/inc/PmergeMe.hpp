/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:43:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/02 18:49:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <stdexcept>
#include <limits>
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
				typedef std::random_access_iterator_tag 							iterator_category;
				typedef typename std::iterator_traits<Iterator>::value_type 		value_type;
				typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
				typedef typename std::iterator_traits<Iterator>::pointer 			pointer;
				typedef typename std::iterator_traits<Iterator>::reference 			reference;

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

// Utilities
template<typename Iterator>
void	iter_swap(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs);

// Iterate functions
template<typename Iterator>
GroupIterator<Iterator>	next(GroupIterator<Iterator> it, std::size_t n);

template<typename Iterator>
GroupIterator<Iterator>	prev(GroupIterator<Iterator> it, std::size_t n);

// Comparison operators
template<typename Iterator1, typename Iterator2>
bool	operator==(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs);

template<typename Iterator1, typename Iterator2>
bool	operator!=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs);

// Arithmetic operators
template <typename Iterator>
GroupIterator<Iterator>	operator+(GroupIterator<Iterator> it, std::size_t size);

template <typename Iterator>
GroupIterator<Iterator>	operator+(std::size_t size, GroupIterator<Iterator> it);

template <typename Iterator>
GroupIterator<Iterator>	operator-(GroupIterator<Iterator> it, std::size_t size);

template <typename Iterator>
typename GroupIterator<Iterator>::difference_type	operator-(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs);

// Construction functions
template<typename Iterator>
GroupIterator<Iterator>	makeGroupIterator(Iterator it, std::size_t size);

template<typename Iterator>
GroupIterator<Iterator>	makeGroupIterator(GroupIterator<Iterator> it, std::size_t size);




class PmergeMe{
	public:
				PmergeMe(void);
				PmergeMe(const PmergeMe& other);
				~PmergeMe(void);

				PmergeMe&	operator=(const PmergeMe& rhs);
				
				void	parseInput(char **input);
				template <typename T> void	printElements(const T& container);
				int		sortVector(void);
				int		sortList(void);
				void	fjaVec(GroupIterator<std::vector<int>::iterator> first,
							GroupIterator<std::vector<int>::iterator> last,
							int& compare);
				void	fjaList(GroupIterator<std::list<int>::iterator> first,
							GroupIterator<std::list<int>::iterator> last,
							int& compare);
	private:
				std::vector<int>	_vec;
				std::list<int>		_list;				
};
