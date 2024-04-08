/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:32 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/08 11:55:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

/* CONSTRUCTORS */
template <typename T>
MutantStack<T>::MutantStack(void){
	if (VERBOSE)
		std::cout << "MutantStack default constructor called" << std::endl;
	return;	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other){
	if (VERBOSE)
		std::cout << "MutantStack copy constructor called" << std::endl;
	*this = other;
	return;
}

template <typename T>
MutantStack<T>::~MutantStack(void){
	if (VERBOSE)
		std::cout << "MutantStack destructor called" << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& rhs){
	if (VERBOSE)
		std::cout << "MutantStack assignment operator called" << std::endl;
	if (this != &rhs)
		static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(rhs);
	return *this;
}
