/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:14:40 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/27 18:17:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char** argv){
	if (argc != 2)
		std::cerr << "invalid number of arguments" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}