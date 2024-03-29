/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:14:56 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/29 17:17:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C.hpp"

/* CONSTRUCTORS */

C::C(void){
	std::cout << "C constructor called" << std::endl;
	return;
}

C::~C(void){
	std::cout << "C destructor called" << std::endl;
	return;
}
