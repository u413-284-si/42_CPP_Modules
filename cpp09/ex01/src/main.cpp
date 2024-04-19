/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:30:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 20:54:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

void	runTests(const std::string& name, size_t total,\
			const std::pair<std::string, double> tests[]){
	size_t	passed = 0;
	int		result;
	
	std::cout << "\n* " << name << " *\n";
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
					std::cout << GREEN << "SUCCESS -- result: " << result;
					std::cout << RESET << std::endl;
					passed++;
				}
			}
			catch(std::exception& e){
				std::cerr << BLUE << "Error: " << e.what() << RESET << std::endl;
			}
		}
	}
	std::cout << CYAN << "\nTEST END\n" << passed << " of " << total;
	std::cout << " passed" << RESET << std::endl;
	return;
}

void	testValid(void){
	std::pair<std::string, double>	tests[] = {
		std::make_pair("8 9 * 9 - 9 - 9 - 4 - 1 +", 42),
		std::make_pair("7 7 * 7 -", 42),
		std::make_pair("1 2 * 2 / 2 * 2 4 - +", 0),
		std::make_pair("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", 42),
		std::make_pair("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", 15),
		std::make_pair("4      6 *      2          +    ", 26),
		std::make_pair("3 9 - 9 - 3 *", -45),
	};
	runTests("VALID OPERATIONS", sizeof(tests) / sizeof(tests[0]), tests);
	return;
}

void	testInvalid(void){
	std::pair<std::string, double>	tests[] = {
		std::make_pair("(1 + 1)", 42),
		std::make_pair("7.0 7.0 * 7.0 -", 42),
		std::make_pair("7 7 * 42 -", 42),
		std::make_pair("1 z +", 42),
		std::make_pair("1 1 ", 42),
		std::make_pair("1 0 /", 42),
		std::make_pair("1 -", 42),
		std::make_pair("1 1 2 ++", 42),
		std::make_pair("1 1 2 +", 42),
		std::make_pair("", 42),
	};
	runTests("INVALID OPERATIONS", sizeof(tests) / sizeof(tests[0]), tests);
	return;
}

void	unitTester(void){
	testValid();
	testInvalid();
	return;
}

int		main(int argc, char **argv){
	/* // For testing
	(void)argc;
	(void)argv;
	unitTester(); */
	RPN	calculator;

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
	}
	return 0;
}
