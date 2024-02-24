/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:25:18 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/24 14:19:59 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
	mode[0] = &Harl::debug;
	mode[1] = &Harl::info;
	mode[2] = &Harl::warning;
	mode[3] = &Harl::error;
	return;
}

Harl::~Harl(void){
	return;
}

void	Harl::complain(std::string level){
	int		lv = convertLevel(level);
	
	if (lv < 0)
		return;
	(this->mode[lv])();
	return;
}

int		Harl::convertLevel(const std::string level){
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (level == levels[i])
			return i;
	}
	std::cerr << "Invalid level. You moron." << std::endl;
	return -1;
}

void	Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return;
}

void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}
