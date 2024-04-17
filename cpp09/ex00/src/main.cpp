/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:19:22 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/17 13:22:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: insufficient arguments." << std::endl;
		return 1;
	}
	try{
		BitcoinExchange	btc;
		btc.parseInput(argv[1]);
		//btc.printData();
	}
	catch(std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
