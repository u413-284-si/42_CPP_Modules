/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:04 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 14:55:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Constructor with totalAmount initialised to initial_deposit
Account::Account(int initial_deposit):_totalAmount(initial_deposit),
									  _totalNbDeposits(1){
	return;
}

// Destructor
Account::~Account(void){
	return;
}

