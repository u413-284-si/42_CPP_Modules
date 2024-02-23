/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/23 13:24:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	std::string	line;
	
	if (argc != 4){
		std::cout << "Wrong program call. Usage is" << std::endl;
		std::cout << "./replace <file name> <string to be replaced> <replacing string>" << std::endl;
		return 1;
	}
	std::ifstream	file(argv[1]);
	if (file.is_open()){
		while (std::getline(file, line)){
			
		}
		file.close();
	}
	else
		std::cout << "Unable to open file. Much sad." << std::endl;
	return 0;
}
