/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:30:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 14:39:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int	main(int argc, char **argv){
	RPN	calculator;

	if (argc != 2){
		std::cout << "Error: insufficient arguments\n";
		std::cout << "expected: ./RPN <operation string>" << std::endl;
	}
	try{
		calculator.parseInput(argv[1]);
		std::cout << calculator.getResult() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
