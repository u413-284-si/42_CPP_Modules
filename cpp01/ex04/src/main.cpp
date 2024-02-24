/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/24 10:56:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	parseAndReplace(std::string& line, std::string const target, std::string const replace){
	size_t	pos = 0;

	if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		return;
	while (pos != line.length() - 1){
		pos = line.find(target, pos);
		line.erase(pos, target.length());
		line.insert(pos, replace);
		pos++;
	}
	return;
}

int	main(int argc, char **argv){
	std::string	line;
	
	if (argc != 4){
		std::cerr << "Wrong program call. Usage is" << std::endl;
		std::cerr <<  argv[0] << " <file name> <string to be replaced> <replacing string>" << std::endl;
		return 1;
	}
	std::ifstream	file(argv[1]);
	if (!file.is_open()){
		std::cerr << "Unable to open file " << argv[1] << ". Much sad." << std::endl;
		return 2;
	}
	std::string		newstr = argv[1];
	newstr.append(".replace");
	std::ofstream	newfile(newstr.c_str());
	if (!newfile.is_open()){
		std::cerr << "Unable to create file " << newstr << ". More sad." << std::endl;
		return 2;
	}
	while (std::getline(file, line)){
		parseAndReplace(line, argv[2], argv[3]);
		newfile << line;
	}
	file.close();
	newfile.close();
	return 0;
}
