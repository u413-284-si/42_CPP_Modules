/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:33:06 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/03 12:54:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ====================== GROUPITERATOR CLASS ============================= */

/* CONSTRUCTORS */

template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(void) : _it(NULL), _size(0){
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

/* ELEMENT ACCESS OPERATORS */
template <typename Iterator>
Iterator	GroupIterator<Iterator>::operator[](std::size_t pos){
	return this->_it[pos * this->_size + this->_size - 1];
}

template <typename Iterator>
Iterator	GroupIterator<Iterator>::operator[](std::size_t pos) const{
	return this->_it[pos * this->_size + this->_size - 1];
}


/* UTILITIES */
template<typename Iterator>
void	iter_swap(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs){
	std::swap_ranges(lhs.getIterator(), lhs.getIterator() + lhs.getSize(), rhs.getIterator());
	return;
}

/* ITERATE FUNCTIONS */
template <typename Iterator>
GroupIterator<Iterator>		next(GroupIterator<Iterator> it, std::size_t n){
	std::advance(it, n);
	return it;
}

template <typename Iterator>
GroupIterator<Iterator>		prev(GroupIterator<Iterator> it, std::size_t n){
	std::advance(it, -n);
	return it;
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

/* RELATIONAL OPERATORS */
template<typename Iterator>
bool	operator<(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs){
	return lhs.getIterator() < rhs.getIterator();
}

template<typename Iterator>
bool	operator<=(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs){
	return lhs.getIterator() <= rhs.getIterator();
}

template<typename Iterator>
bool	operator>(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs){
	return lhs.getIterator() > rhs.getIterator();
}

template<typename Iterator>
bool	operator>=(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs){
	return lhs.getIterator() >= rhs.getIterator();
}

/* ARITHMETIC OPERATORS */
template <typename Iterator>
GroupIterator<Iterator>	operator+(GroupIterator<Iterator> it, std::size_t size){
	return it += size;
}

template <typename Iterator>
GroupIterator<Iterator>	operator+(std::size_t size, GroupIterator<Iterator> it){
	return it += size;
}

template <typename Iterator>
GroupIterator<Iterator>	operator-(GroupIterator<Iterator> it, std::size_t size){
	return it -= size;
}

template <typename Iterator>
typename GroupIterator<Iterator>::difference_type	operator-(const GroupIterator<Iterator>& lhs,
															 const GroupIterator<Iterator>& rhs){
	return (lhs.getIterator() - rhs.getIterator()) / lhs.getSize();
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
		if (tmp > std::numeric_limits<int>::max())
			throw std::invalid_argument("integer overflow found");			
		this->_vec.push_back(static_cast<int>(tmp));
		this->_list.push_back(static_cast<int>(tmp));
	}
	return;
}

template <typename T>
void	PmergeMe::printElements(const T& container){
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << std::endl;
	return;
}

int		PmergeMe::sortVector(void){
	GroupIterator<std::vector<int>::iterator>	first = makeGroupIterator(this->_vec.begin(), 1);;
	GroupIterator<std::vector<int>::iterator>	last = makeGroupIterator(this->_vec.end(), 1);
	int											compare = 0;

	fjaVec(first, last, compare);
	printElements(_vec);
	return compare;	
}

/* Implementation of the Ford-Johnson algorithm using vector as container
 */
void	PmergeMe::fjaVec(GroupIterator<std::vector<int>::iterator> first,
							GroupIterator<std::vector<int>::iterator> last,
							int& compare){
	std::size_t	size = std::distance(first, last);
	
	// Exit when only one element present
	if (size < 2)
		return;

	// Determine if a stray element is present (= when amount of numbers is uneven)
	// If so, leave last element in container out of current focus 
	bool		has_stray = (size % 2 != 0);
	GroupIterator<std::vector<int>::iterator>	end = has_stray ? prev(last, 1) : last;
	
	// Create pairs by comparing two consecutive numbers
	// Position larger number first
	for (GroupIterator<std::vector<int>::iterator> it = first; it != end; it += 2){
		if (it[1] < it[0])
			iter_swap(it, next(it, 1));
		compare++;
	}

	// Recursively sort the pairs by the larger number, creating a sorted 
	// sequence in ascending order
	fjaVec(makeGroupIterator(first, 2), makeGroupIterator(end, 2), compare);
}
