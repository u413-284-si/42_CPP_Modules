/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:05:18 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/25 15:12:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv){
	Harl	harl;
	
	if (argc != 2){
		std::cerr << "Invalid program use.\nUsage: " << argv[0];
		std::cerr << " <log level>" << std::endl;
		return -1; 
	}
	harl.complain(argv[1]);
	return 0;
}