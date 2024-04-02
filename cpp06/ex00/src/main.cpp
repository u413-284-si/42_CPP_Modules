/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:14:40 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/27 19:18:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "invalid number of arguments\n";
		std::cerr << "expected: ./conv <input>" << std::endl;
	}
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
