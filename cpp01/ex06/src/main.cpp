/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:05:18 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/26 18:57:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv){
	Harl	harl;
	int		lvl;
	
	if (argc != 2){
		std::cerr << "Invalid program use.\nUsage: " << argv[0];
		std::cerr << " <log level>" << std::endl;
		return -1; 
	}
	lvl = harl.convertLevel(argv[1]);
	switch (lvl)
	{
		case 0:			
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}