/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:08:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/08 12:40:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <stack>

/* ====== DEFINITIONS ====== */

# define VERBOSE 0

/* ====== CLASS DECLARATION ====== */

template <typename T>
class MutantStack : public std::stack<T>{
	public:
				MutantStack(void);
				MutantStack(const MutantStack& other);
				~MutantStack(void);

				MutantStack&	operator=(const MutantStack& rhs);
				
				//typedefs
				typedef typename std::stack<T>::container_type				container_type;
				typedef typename container_type::iterator					iterator;
				typedef typename container_type::const_iterator				const_iterator;
				typedef typename container_type::reverse_iterator			reverse_iterator;
				typedef typename container_type::const_reverse_iterator		const_reverse_iterator;
				
				//functions returning the appropritate iterators;
				//accessing protected member c of std::stack representing the
				//underlying container
				iterator				begin(void){ return this->c.begin(); }
				iterator				end(void){ return this->c.end(); }
				const_iterator			cbegin(void) const{ return this->c.begin(); }
				const_iterator			cend(void) const{ return this->c.end(); }
				reverse_iterator		rbegin(void){ return this->c.rbegin(); }
				reverse_iterator		rend(void){ return this->c.rend(); }
				const_reverse_iterator	crbegin(void) const{ return this->c.rbegin(); }
				const_reverse_iterator	crend(void) const{ return this->c.rend(); }
};

#include "../src/MutantStack.tpp"
