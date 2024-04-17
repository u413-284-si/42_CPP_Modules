/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:21:52 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/17 14:03:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange(void){
	std::ifstream	data("./data/data.csv");
	//std::ifstream	data("./tests/wrongheader.csv");
	std::string		line;
	time_t			date;
	double			rate;
	unsigned int	lineCount;
	unsigned int	validCount;
	
	if (!data.is_open())
		throw std::runtime_error("could not open file.");
	std::getline(data, line);
	if(checkHeader(line, "date", ",", "exchange_rate"))
		throw std::runtime_error("invalid header\nexpected: date,exchange_rate");
	lineCount = 1;
	validCount = 0;
	std::cout << "Reading database...\n";
	while (std::getline(data, line)){
		lineCount++;
		try{
			checkLine(line, date, rate, false);
			this->_xChangeRate.insert(std::make_pair(date, rate));
			validCount++;
		}
		catch(std::exception& e){
			std::cerr << "Invalid line " << lineCount << ": " << e.what() << std::endl;
		}
	}
	std::cout << validCount << "/" << lineCount - 1 << " data lines valid\n";
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

int		BitcoinExchange::checkHeader(const std::string& line,\
			const std::string& key, const std::string& delim,\
			const std::string& value) const{
	std::string	expectedheader;

	expectedheader = key + delim + value;
	return line.compare(expectedheader);
}

void	BitcoinExchange::checkLine(const std::string& line, time_t& date,\
			double& value, bool valueFromInput) const{
	std::size_t			pos;
	std::string	strDate;
	std::string	strValue;

	if (line.empty())
		throw std::invalid_argument("empty line detected");
	pos = line.find(','); 
	if (pos == std::string::npos)
		throw std::invalid_argument("no delimiter found");
	strDate = line.substr(0, pos++);
	checkDate(strDate, date);
	strValue = line.substr(pos, std::string::npos - pos);
	if (valueFromInput)
		checkValue(strValue, value);
	else
		checkRate(strValue, value);
	return;
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
	initialiseTimeStruct(time);
	// struct tm measures years starting from 1900
	time.tm_year = year - 1900;
	// struct tm measures months in range 0 - 11
	time.tm_mon = month - 1;
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
	if (rate < 0)
		throw std::invalid_argument("not a positive number.");
	return;
}

void	BitcoinExchange::checkValue(const std::string& strValue, double& value) const{
	char	*endptr;
	if (strValue.empty())
		throw std::invalid_argument("no value given");
	value = strtod(strValue.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::invalid_argument("invalid value format");
	if (value < 0)
		throw std::invalid_argument("not a positive number.");
	if (value > 1000)
		throw std::invalid_argument("too large a number.");
	return;
}

void	BitcoinExchange::parseInput(const char *input) const{
	std::ifstream	data(input);
	std::string		line;
	time_t			date;
	double			value;
	double			result;

	if (!data.is_open())
		throw std::runtime_error("could not open file.");
	std::getline(data, line);
	if(checkHeader(line, "date", " | ", "value"))
		throw std::runtime_error("invalid header\nexpected: date | value");
	std::cout << "Reading input...\n";
	while (std::getline(data, line)){
		try{
			checkLine(line, date, value, true);
			// compare date to key in _xchangeRate
			// find match or next lower date and multiply value with stored rate
			// print out result message
			printResult(date, value, result);
		}
		catch(std::exception& e){
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	data.close();
	return;
}

std::string	BitcoinExchange::getDate(const time_t& date) const{
	std::tm				*t;
	std::ostringstream	strDate;
	int					month;
	int					day;

	t = std::localtime(&date);
	// struct tm measures years starting from 1900
	strDate << t->tm_year + 1900 << "-";
	// struct tm measures months in range 0 - 11
	month = t->tm_mon + 1;
	if (month < 10)
		strDate << "0";
	strDate << month << "-";
	day = t->tm_mday;
	if (day < 10)
		strDate << "0";
	strDate << day;
	return strDate.str();
}

void	BitcoinExchange::printData(void) const{
	std::map<time_t, double>::const_iterator	cit;
	std::map<time_t, double>::const_iterator	cite;

	cit = this->_xChangeRate.begin();
	cite = this->_xChangeRate.end();
	while (cit != cite){
		std::cout.precision(2);
		std::cout << getDate(cit->first) << "," << std::fixed << cit->second << "\n";
		cit++;
	}
	return;
}

void	BitcoinExchange::printResult(const time_t& date, const double& value,\
								const double& result) const{
	std::cout << getDate(date) << " => " << value << " = " << result << std::endl;
	return;									
}

// Helper functions

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

/*  Time structs need to be initialised to 0 to avoid the conversion to time_t
 with mktime to return random values. */
void	BitcoinExchange::initialiseTimeStruct(std::tm& t) const{
	t.tm_gmtoff = 0;
	t.tm_hour = 0;
	t.tm_isdst = 0;
	t.tm_mday = 0;
	t.tm_min = 0;
	t.tm_mon = 0;
	t.tm_sec = 0;
	t.tm_wday = 0;
	t.tm_yday = 0;
	t.tm_year = 0;
	t.tm_zone = 0;
	return;
}
