/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:23:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/05 21:25:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <cstdlib>

/* ====== DECLARATIONS ====== */

template <typename T>
class Array{
	public:
				Array<T>(void);
				Array<T>(const unsigned int n);
				Array<T>(const Array& other);
				~Array<T>(void);

				Array<T>&		operator=(const Array<T>& rhs);
				T&				operator[](const unsigned int n);
				T				operator[](const unsigned int n) const;

				unsigned int	size(void) const;
	private:	
				unsigned int	_n;
				T				*_arr;
};

#include "../src/Array.tpp"
