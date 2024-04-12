/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:21:52 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/11 19:32:54 by sqiu             ###   ########.fr       */
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
		try{
			checkLine(line, date, rate);
			this->_xChangeRate.insert(std::make_pair(date, rate));
		}
		catch(std::exception& e){
			std::cerr << "Invalid line " << lineCount << ": " e.what() << std::endl;
		}
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

int		BitcoinExchange::checkHeader(const std::string& line) const{
	return line.compare("date,exchange_rate");
}

void	BitcoinExchange::checkLine(const std::string& line, time_t& date, double& rate) const{
	if (line.find(',') == std::string::npos)
		throw std::invalid_argument("no delimiter found");
	checkDate(line, date);
	checkRate(line, rate);
	return;
}

void	BitcoinExchange::checkDate(const std::string& line, time_t& date) const{
	std::size_t	pos = line.find(',');
	std::string	date = line.substr(0, pos);
	char		*szy;
	char		*szm;
	char		*szd;
	double		year = stod(line.substr(0, 4).c_str(), &szy);
	double		month = stod(line.substr(5, 2).c_str(), &szm);
	double		day = stod(line.substr(8, 2).c_str(), &szd);
	

	if (date.length() != 10)
		throw std::invalid_argument("date length invalid");
	if (date.)
}

void	BitcoinExchange::checkRate(const std::string& line, double& rate){

}
