/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/29 18:18:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	parseAndReplace(std::string& line, const std::string& target, const std::string& replace){
	size_t		pos = 0;
	size_t		start = 0;
	std::string	tmp;

	pos = line.find(target, start);
	while (pos != std::string::npos){
		tmp.append(line, start, pos - start);
		tmp.append(replace);
		start = pos + target.length();
		pos = line.find(target, start);
	}
	tmp.append(line, start, pos - start);
	tmp += '\n';
	return tmp;
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
		file.close();
		std::cerr << "Unable to create file " << newstr << ". More sad." << std::endl;
		return 2;
	}
	while (std::getline(file, line)){
		line = parseAndReplace(line, argv[2], argv[3]);
		newfile << line;
	}
	file.close();
	newfile.close();
	return 0;
}
