/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:58:44 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/06 18:18:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <algorithm>
#include <stdexcept>

/* ====== DEFINITIONS ====== */

/* In C++, when dealing with dependent names, such as types nested within
template parameters (T in this case), you need to use the typename keyword
to indicate to the compiler that T::iterator is a type.
 */
template <typename T>
typename T::iterator	easyfind(T& container, const int n){
	typename T::iterator	result;
	
	result = find(container.begin(), container.end(), n);
	if (result == container.end())
		throw std::runtime_error("error: value not found");
	else
		return result;
}

template <typename T>
typename T::const_iterator	easyfind(const T& container, const int n){
	typename T::const_iterator	result;
	
	result = find(container.begin(), container.end(), n);
	if (result == container.end())
		throw std::runtime_error("error: value not found");
	else
		return result;
}
