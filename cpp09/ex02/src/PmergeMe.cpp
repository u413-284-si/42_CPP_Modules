/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:33:06 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/25 18:25:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ====================== GROUPITERATOR CLASS ============================= */

/* CONSTRUCTORS */

template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(void){
	if (VERBOSE)
		std::cout << "[GroupIterator] Default constructor called." << std::endl;
	return;
}

template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(Iterator it, std::size_t size)
												: _it(it), _size(size){
	if (VERBOSE)
		std::cout << "[GroupIterator] Param constructor called." << std::endl;
	return;
}

template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(const GroupIterator& other){
	if (VERBOSE)
		std::cout << "[GroupIterator] Copy constructor called." << std::endl;
	*this = other;
	return;
}

template <typename Iterator>
GroupIterator<Iterator>::~GroupIterator(void){
	if (VERBOSE)
		std::cout << "[GroupIterator] Destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

template <typename Iterator>
GroupIterator<Iterator>&	GroupIterator<Iterator>::operator=(const GroupIterator& rhs){
	if (VERBOSE)
		std::cout << "[GroupIterator] Assignment operator called." << std::endl;
	if (this != &rhs){
		this->_it = rhs.getIterator();
		this->_size = rhs.getSize();
	}
	return *this;
}

/* MEMBER ACCESS */

template <typename Iterator>
Iterator	GroupIterator<Iterator>::getIterator(void) const{
	return this->_it;
}

template <typename Iterator>
std::size_t	GroupIterator<Iterator>::getSize(void) const{
	return this->_size;
}

/* ELEMENT ACCESS */

template <typename Iterator>
typename GroupIterator<Iterator>::reference	GroupIterator<Iterator>::operator*(void) const{
	return *(this->_it);
}

template <typename Iterator>
typename GroupIterator<Iterator>::pointer	GroupIterator<Iterator>::operator->(void) const{
	return &(operator*());
}

/* INCREMENT/DECREMENT OPERATORS */

template <typename Iterator>
GroupIterator<Iterator>&	GroupIterator<Iterator>::operator++(void){
	this->_it += this->_size;
	return *this;
}

template <typename Iterator>
GroupIterator<Iterator>	GroupIterator<Iterator>::operator++(int){
	GroupIterator<Iterator>	tmp = *this;
	operator++();
	return tmp;
}

template <typename Iterator>
GroupIterator<Iterator>&	GroupIterator<Iterator>::operator--(void){
	this->_it -= this->_size;
	return *this;
}

template <typename Iterator>
GroupIterator<Iterator>	GroupIterator<Iterator>::operator--(int){
	GroupIterator<Iterator>	tmp = *this;
	operator--();
	return tmp;
}

template <typename Iterator>
GroupIterator<Iterator>&	GroupIterator<Iterator>::operator+=(std::size_t increment){
	this->_it += this->_size * increment;
	return *this;
}

template <typename Iterator>
GroupIterator<Iterator>&	GroupIterator<Iterator>::operator-=(std::size_t increment){
	this->_it -= this->_size * increment;
	return *this;
}

/* UTILITIES */
template<typename Iterator1, typename Iterator2>
void	iter_swap(GroupIterator<Iterator1> lhs, GroupIterator<Iterator2> rhs){
	std::swap_ranges(lhs.getIterator(), lhs.getIterator() + lhs.getSize(), rhs.getIterator());
	return;
}

/* COMPARISON OPERATORS */
template<typename Iterator1, typename Iterator2>
bool	operator==(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs){
	return lhs.getIterator() == rhs.getIterator();
}

template<typename Iterator1, typename Iterator2>
bool	operator!=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs){
	return lhs.getIterator() != rhs.getIterator();
}

/* CONSTRUCTION FUNCTIONS */
template<typename Iterator>
GroupIterator<Iterator>	makeGroupIterator(Iterator it, std::size_t size){
	return GroupIterator<Iterator>(it, size);
}

template<typename Iterator>
GroupIterator<Iterator>	makeGroupIterator(GroupIterator<Iterator> it, std::size_t size){
	return GroupIterator<Iterator>(it.getIterator(), it.getSize() * size);
}


/* ====================== PMERGEME CLASS ============================= */

/* CONSTRUCTORS */

PmergeMe::PmergeMe(void){
	if (VERBOSE)
		std::cout << "[PmergeMe] Default constructor called." << std::endl;
	return;
}

PmergeMe::PmergeMe(const PmergeMe& other){
	if (VERBOSE)
		std::cout << "[PmergeMe] Copy constructor called." << std::endl;
	*this = other;
	return;
}

PmergeMe::~PmergeMe(void){
	if (VERBOSE)
		std::cout << "[PmergeMe] Destructor called." << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs){
	if (VERBOSE)
		std::cout << "[PmergeMe] Assignment operator called." << std::endl;
	if (this != &rhs){
		this->_list = rhs._list;
		this->_vec = rhs._vec;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

void	PmergeMe::parseInput(char **input){
	double	tmp = 0;
	char	*endptr;
	
	for (int i = 1; input[i] != NULL; i++){
		if (input[i][0] == '\0')
			throw std::invalid_argument("empty string found");
		tmp = strtod(input[i], &endptr);
		if (*endptr != '\0')
			throw std::invalid_argument("invalid arg format");
		if (tmp < 0)
			throw std::invalid_argument("only positive numbers accepted");
		this->_vec.push_back(static_cast<int>(tmp));
		this->_list.push_back(static_cast<int>(tmp));
	}
	return;
}