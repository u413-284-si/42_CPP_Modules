/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:21:52 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/08 21:58:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange(void){
	std::ifstream	data("../data.csv");
	std::string		line;
	time_t			date;
	double			rate;
	unsigned int	lineCount;
	
	if (!data.is_open())
		throw std::runtime_error("could not open file.");
	std::getline(data, line);
	if(checkHeader(line))
		throw std::runtime_error("invalid header");
	lineCount = 1;
	while (std::getline(data, line)){
		lineCount++;
		if (checkLine(line, date, rate)){
			std::cerr << "Invalid line " << lineCount << std::endl;
			continue;
		}
		this->_xChangeRate.insert(std::make_pair(date, rate));
	}
	data.close();
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	*this = other;
	return;
}

BitcoinExchange::~BitcoinExchange(void){
	return;
}

/* OPERATOR OVERLOADING */

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs){
	if (this != &rhs)
		this->_xChangeRate = rhs._xChangeRate;
	return *this;
}

/* MEMBER FUNCTIONS */

int	BitcoinExchange::checkHeader(const std::string& line){
	return line.compare("date,exchange_rate");
}

int	BitcoinExchange::checkLine(const std::string& line, time_t& date, double& rate){
	if (line.find(',') == std::string::npos)
		return 1;
}
