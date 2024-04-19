/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:30:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 15:55:34 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

void	unitTester(const std::string& name, size_t total,\
			const std::pair<std::string, double> tests[]){
	size_t	passed = 0;
	int		result;
	
	std::cout << "* " << name << " *\n";
	for (size_t i = 0; i < total; i++){
		std::cout << "Test [" << i << "]: " << tests[i].first << std::endl;
		{
			RPN 	calculator;
			try{
				calculator.parseInput(tests[i].first);
				result = calculator.getResult();
				if (result != tests[i].second){
					std::cerr << RED << "FAILURE\nexpected: " << tests[i].second;
					std::cerr << "; calculated: " << calculator.getResult();
					std::cerr << RESET << std::endl;
				}
				else{
					std::cout << GREEN << "SUCCESS\nresult: " << result;
					std::cout << RESET << std::endl;
					passed++;
				}
			}
			catch(std::exception& e){
				std::cerr << BLUE << "Error: " << e.what() << RESET << std::endl;
			}
		}
	}
	std::cout << CYAN << passed << " of " << total << " passed" << RESET;
	std::cout << std::endl;
	return;
}

void	testValid(void){
	std::pair<std::string, double>	tests[] = {
		std::make_pair("8 9 * 9 - 9 - 9 - 4 - 1 +", 42),
		std::make_pair("7 7 * 7 -", 42),
		std::make_pair("1 2 * 2 / 2 * 2 4 - +", 0),
		std::make_pair("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", 15),
	};
	unitTester("VALID OPERATIONS", sizeof(tests) / sizeof(tests[0]), tests);
	return;
}

int		main(int argc, char **argv){
	// For testing
	(void)argc;
	(void)argv;
	testValid();
/* 	RPN	calculator;

	if (argc != 2){
		std::cout << "Error: insufficient arguments\n";
		std::cout << "expected: ./RPN <operation string>" << std::endl;
		return -1;
	}
	try{
		calculator.parseInput(argv[1]);
		std::cout << calculator.getResult() << std::endl;
	}
	catch(std::exception& e){
		std::cout << BLUE << "Error: " << e.what() << RESET << std::endl;
	} */
	return 0;
}
