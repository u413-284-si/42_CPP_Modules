/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:57:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/15 17:50:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main(int argc, char **argv){
	PmergeMe	p;
	
	if (argc < 2){
		std::cout << RED << "Error: insufficient arguments\nexpected: ";
		std::cout << argv[0] << " <list of positive integers>" << RESET << std::endl;
		return 1;
	}
	try{
		p.checkInput(argv);
	}
	catch(std::exception& e){
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	p.handleInputWithVector(argv);
	return 0;
}
