/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:43:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/16 16:51:31 by sqiu             ###   ########.fr       */
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
#include <ctime>

/* ====== DEFINITIONS ====== */

# define VERBOSE 0
# define JACOBSTHAL_DIFF_SIZE 63

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

				// Element access operators
				typename GroupIterator::reference	operator[](std::size_t pos);
				typename GroupIterator::reference	operator[](std::size_t pos) const;

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

// Relational operators
template<typename Iterator>
bool	operator<(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs);

template<typename Iterator>
bool	operator<=(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs);

template<typename Iterator>
bool	operator>(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs);

template<typename Iterator>
bool	operator>=(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs);

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


/* ====================== PMERGEME CLASS ============================= */

// Node struct for pend elements of vector implementation
struct node{
	GroupIterator<std::vector<int>::iterator>	it;
	typename std::list< GroupIterator<std::vector<int>::iterator> >::iterator next;
};

class PmergeMe{
	public:
				PmergeMe(void);
				PmergeMe(const PmergeMe& other);
				~PmergeMe(void);

				PmergeMe&	operator=(const PmergeMe& rhs);
				
				void						checkInput(char **input);
				template <typename T> void	printElements(const T& container);
				
				void						handleInputWithVector(char** input);
				int							sortVector(void);
				void						fjaVector(GroupIterator<std::vector<int>::iterator> first,
												GroupIterator<std::vector<int>::iterator> last,
												int& nComp);
				std::list< GroupIterator<std::vector<int>::iterator> >::iterator	binaryInsertVector(
					std::list< GroupIterator<std::vector<int>::iterator> >::iterator begin,
					std::list< GroupIterator<std::vector<int>::iterator> >::iterator end,
					GroupIterator<std::vector<int>::iterator> val, int& nComp);
				bool						compareVectorIt(std::list< GroupIterator<std::vector<int>::iterator> >::iterator it,
												GroupIterator<std::vector<int>::iterator> val, int& nComp);

				void						handleInputWithList(char** input);							
				int							sortList(void);
				void						fjaList(GroupIterator<std::list<int>::iterator> first,
												GroupIterator<std::list<int>::iterator> last,
												int& nComp);
				std::list< GroupIterator<std::list<int>::iterator> >::iterator	binaryInsertList(
					std::list< GroupIterator<std::list<int>::iterator> >::iterator begin,
					std::list< GroupIterator<std::list<int>::iterator> >::iterator end,
					GroupIterator<std::list<int>::iterator> val, int& nComp);
				bool						compareListIt(std::list< GroupIterator<std::list<int>::iterator> >::iterator it,
												GroupIterator<std::list<int>::iterator> val, int& nComp);
	private:
				std::vector<int>	_vec;
				std::list<int>		_list;				
};
