/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:25:18 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/25 16:16:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
	return;
}

Harl::~Harl(void){
	return;
}

void	Harl::complain(std::string level){
	int		lv = convertLevel(level);
	const pointerMF	mode[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	if (lv < 0)
		return;
	for (int i = 0; (lv + i) < 4; i++)
		(this->*(mode[lv + i]))();
	return;
}

int		Harl::convertLevel(const std::string level){
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (level == levels[i])
			return i;
	}
	return -1;
}

void	Harl::debug(void){
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
	return;
}

void	Harl::info(void){
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	return;
}

void	Harl::error(void){
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
	return;
}
