/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:05 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/09 19:01:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

// Handle const arrays
template <typename T>
void	iter(const T *arr, const size_t size, void (* const func)(const T&)){
	if (!arr)
		return;
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
	return;
}

// Handle non-const arrays
template <typename T>
void	iter(T *arr, const size_t size, void (* const func)(T&)){
	if (!arr)
		return;
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
	return;
}
