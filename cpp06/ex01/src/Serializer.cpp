/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:45:56 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/27 19:53:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

/* CONSTRUCTORS */

Serializer::Serializer(void){
	return;
}

Serializer::Serializer(const Serializer& other){
	*this = other;
	return;
}

Serializer::~Serializer(void){
	return;
}

/* OPERATOR OVERLOADING */

Serializer&	Serializer::operator=(const Serializer& rhs){
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

uintptr_t	Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
