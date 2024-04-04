/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:25:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/04 13:36:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

template <typename T>
void	swap(T& x, T& y){
	T	buf = x;
	
	x = y;
	y = buf;
	return;	
}

template <typename T>
const T&	min(const T& x, const T& y){
	return (x < y ? x : y);
}

template <typename T>
const T&	max(const T& x, const T& y){
	return (x > y ? x : y);
}
