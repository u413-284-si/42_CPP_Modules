/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:41:42 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 13:14:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <limits.h>
#include <algorithm>

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class Span{
	public:
				Span(const unsigned int N);
				Span(const Span& other);
				~Span(void);

				Span&	operator=(const Span& rhs);

				void						addNumber(const int x);
				template <typename T> void	insert(T first, T last);
				unsigned int				shortestSpan(void);
				unsigned int				longestSpan(void);
				void						printElements(void);
	private:
				unsigned int		_N;
				unsigned int		_occupancy;
				std::vector<int>	_vec;
				Span(void);
};

#include "../src/Span.tpp"
