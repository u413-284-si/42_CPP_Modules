/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/17 14:07:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>

/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class BitcoinExchange{
	public:
				BitcoinExchange(void);
				BitcoinExchange(const BitcoinExchange& other);
				~BitcoinExchange(void);

				BitcoinExchange&	operator=(const BitcoinExchange& rhs);

				void		parseInput(const char *input) const;				
				void		printData(void) const;
				void		printResult(const time_t& date, const double& value,\
								const double& result) const;

	private:
				std::map<time_t, double>	_xChangeRate;

				void		checkLine(const std::string& line,\
								const std::string& delim, time_t& date,\
								double& rate, bool valueFromInput) const;
				int			checkHeader(const std::string& line,\
								const std::string& key, \
								const std::string& delim,\
								const std::string& value) const;
				void		checkDate(const std::string& strDate,\
								time_t& date) const;
				void		checkRate(const std::string& strRate,\
								double& rate) const;
				void		checkValue(const std::string& strValue,\
								double& value) const;
				bool		isLeapYear(const int year) const;
								
				std::string	getDate(const time_t& date) const;
				void		initialiseTimeStruct(std::tm& t) const;
};
