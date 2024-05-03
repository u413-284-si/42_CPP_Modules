/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:33:06 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/03 15:41:48 by sqiu             ###   ########.fr       */
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
GroupIterator<Iterator>		GroupIterator<Iterator>::operator++(int){
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
GroupIterator<Iterator>		GroupIterator<Iterator>::operator--(int){
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
typename GroupIterator<Iterator>::reference	GroupIterator<Iterator>::operator[](std::size_t pos){
	return this->_it[pos * this->_size + this->_size - 1];
}

template <typename Iterator>
typename GroupIterator<Iterator>::reference	GroupIterator<Iterator>::operator[](std::size_t pos) const{
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
	const unsigned long jacobsthal_diff[JACOBSTHAL_DIFF_SIZE] = {
    2ul, 2ul, 6ul, 10ul, 22ul, 42ul, 86ul, 170ul, 342ul, 682ul, 1366ul,
    2730ul, 5462ul, 10922ul, 21846ul, 43690ul, 87382ul, 174762ul, 349526ul, 699050ul,
    1398102ul, 2796202ul, 5592406ul, 11184810ul, 22369622ul, 44739242ul, 89478486ul,
    178956970ul, 357913942ul, 715827882ul, 1431655766ul, 2863311530ul, 5726623062ul,
    11453246122ul, 22906492246ul, 45812984490ul, 91625968982ul, 183251937962ul,
    366503875926ul, 733007751850ul, 1466015503702ul, 2932031007402ul, 5864062014806ul,
    11728124029610ul, 23456248059222ul, 46912496118442ul, 93824992236886ul, 187649984473770ul,
    375299968947542ul, 750599937895082ul, 1501199875790165ul, 3002399751580331ul,
    6004799503160661ul, 12009599006321322ul, 24019198012642644ul, 48038396025285288ul,
    96076792050570576ul, 192153584101141152ul, 384307168202282304ul, 768614336404564608ul,
    1537228672809129216ul, 3074457345618258432ul, 6148914691236516864ul
	};

	std::size_t	size = std::distance(first, last);
	
	// Exit when only one element present
	if (size < 2)
		return;
		
	// STEP 1:
	// Determine if a stray element is present (= when amount of numbers is uneven)
	// If so, leave last element in container out of current focus 
	bool		has_stray = (size % 2 != 0);
	GroupIterator<std::vector<int>::iterator>	end = has_stray ? prev(last, 1) : last;
	
	// STEP 2:
	// Create pairs by comparing two consecutive numbers
	// Position larger number second
	for (GroupIterator<std::vector<int>::iterator> it = first; it != end; it += 2){
		if (it[1] < it[0])
			iter_swap(it, next(it, 1));
		compare++;
	}

	// STEP 3:
	// Recursively sort the pairs by the larger number, creating a sorted 
	// sequence in ascending order
	fjaVec(makeGroupIterator(first, 2), makeGroupIterator(end, 2), compare);

	// STEP 4:
	// Separate main chain and pend chain
	std::list< GroupIterator<std::vector<int>::iterator> >	main;
	std::list< node >										pend;

	// The first pend element is always part of the main chain,
    // so we can safely initialize the list with the first two
    // elements of the sequence
	main.push_back(first);
	main.push_back(next(first, 1));

	// Insert larger elements (second of each pair) into main
	// and smaller elements into pend 
	for (GroupIterator<std::vector<int>::iterator> it = first + 2; it != end; it += 2){
		std::list< GroupIterator<std::vector<int>::iterator> >::iterator	tmp = main.insert(main.end(), next(it, 1));
		node	tmpNode;
		
		tmpNode.it = it;
		tmpNode.next = tmp;
		pend.push_back(tmpNode);
	}

	// If existing, add stray element to pend by giving it main.end() as 
	// insertion point for main
	if (has_stray){
		node theStray;
		
		theStray.it = end;
		theStray.next = main.end();
		pend.push_back(theStray);
	}
}
