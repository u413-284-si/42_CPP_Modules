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
	//std::ifstream	data("./data/data.csv");
	std::ifstream	data("./tests/wrongday.csv");
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
			std::cerr << "Invalid line " << lineCount << ": " << e.what() << std::endl;
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
	std::size_t			pos;
	std::string	strDate;
	std::string	strRate;

	if (line.empty())
		throw std::invalid_argument("empty line detected");
	pos = line.find(','); 
	if (pos == std::string::npos)
		throw std::invalid_argument("no delimiter found");
	strDate = line.substr(0, pos++);
	checkDate(strDate, date);
	strRate = line.substr(pos, std::string::npos - pos);
	checkRate(strRate, rate);
	return;
}

/* Any year that is evenly divisible by 4 is a leap year. However, there is still
a small error that must be accounted for. To eliminate this error, the Gregorian
calendar stipulates that a year that is evenly divisible by 100 is a leap year only
if it is also evenly divisible by 400. */
bool	BitcoinExchange::isLeapYear(const int year) const{
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

void	BitcoinExchange::checkDate(const std::string& strDate, time_t& date) const{
	char		*endy;
	char		*endm;
	char		*endd;
	double		year;
	double		month;
	double		day;
	std::tm		time;
	const unsigned	largeMonths = (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 8) | (1 << 10) | (1 << 12);
	const unsigned	smallMonths = (1 << 4) | (1 << 6) | (1 << 9) | (1 << 11);

	if (strDate.length() != 10)
		throw std::invalid_argument("date length invalid");
	year = strtod(strDate.c_str(), &endy);
	if (*endy != '-')
		throw std::invalid_argument("invalid format: year");
	endy++;
	month = strtod(endy, &endm);
	if (*endm != '-')
		throw std::invalid_argument("invalid format: month");
	endm++;
	day = strtod(endm, &endd);
	if (*endd != '\0')
		throw std::invalid_argument("invalid format: day");

	if (month < 1 || month > 12)
		throw std::invalid_argument("invalid month");
	if (day < 1)
		throw std::invalid_argument("invalid day < 1");

	if ((1 << static_cast<int>(month)) & largeMonths){
		if (day > 31)
			throw std::invalid_argument("invalid day > 31");
	}
	else if ((1 << static_cast<int>(month)) & smallMonths){
		if (day > 30)
			throw std::invalid_argument("invalid day > 30");
	}
	else{
		if (isLeapYear(year)){
			if (day > 29)
				throw std::invalid_argument("invalid day > 29");
		}
		else{
			if (day > 28)
				throw std::invalid_argument("invalid day > 28");
		}
	}
	time.tm_year = year;
	time.tm_mon = month;
	time.tm_mday = day;
	date = mktime(&time);
	return;
}

void	BitcoinExchange::checkRate(const std::string& strRate, double& rate) const{
	char	*endptr;
	if (strRate.empty())
		throw std::invalid_argument("no rate given");
	rate = strtod(strRate.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::invalid_argument("invalid rate format");
	return;
}

void	BitcoinExchange::printData(void) const{
	std::map<time_t, double>::const_iterator	cit;
	std::map<time_t, double>::const_iterator	cite;

	cit = this->_xChangeRate.begin();
	cite = this->_xChangeRate.end();
	while (cit != cite){
		std::cout << cit->first << "," << cit->second << "\n";
		cit++;
	}
	return;
}
