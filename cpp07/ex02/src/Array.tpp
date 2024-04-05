/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:37:11 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/05 19:30:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

/* CONSTRUCTORS */

template <typename T>
Array<T>::Array(void) : _n(0), _arr(new T[0]()){
	std::cout << "Array default constructor called" << std::endl;
	return;
}

template <typename T>
Array<T>::Array(const unsigned int n) : _n(n), _arr(new T[n]()){
	std::cout << "Array param constructor called" << std::endl;
	return;
}

template <typename T>
Array<T>::Array(const Array& other) : _n(other._n), _arr(new T[other._n]()){
	std::cout << "Array copy constructor called" << std::endl;
	for (unsigned int i = 0; i < _n; i++)
		this->_arr[i] = other._arr[i];
	return;
}

template <typename T>
Array<T>::~Array(void){
	std::cout << "Array destructor called" << std::endl;
	delete [] this->_arr;
	return;
}

/* OPERATOR OVERLOADING */

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs){
	std::cout << "Array assignment operator called" << std::endl;
	if (this != &rhs){
		delete [] this->_arr;
		this->_arr = new T[rhs._n];
		this->_n = rhs._n;
		for (unsigned int i = 0; i < _n; i++)
			this->_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int n){
	if (n >= this->_n)
		throw std::exception();
	return this->_arr[n];
}

/* MEMBER FUNCTIONS */

template <typename T>
unsigned int	Array<T>::size(void) const{
	return this->_n;
}
