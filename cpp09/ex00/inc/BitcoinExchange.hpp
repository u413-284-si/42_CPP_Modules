/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/11 19:31:12 by sqiu             ###   ########.fr       */
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
/* #include <string>
#include <cstring> */

/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class BitcoinExchange{
	public:
				BitcoinExchange(void);
				BitcoinExchange(const BitcoinExchange& other);
				~BitcoinExchange(void);

				BitcoinExchange&	operator=(const BitcoinExchange& rhs);

				void				checkLine(const std::string& line, time_t& date, double& rate) const;
				int					checkHeader(const std::string& line) const;
				void				checkDate(const std::string& line, time_t& date) const;
				void				checkRate(const std::string& line, double& rate) const;
				bool				isLeapYear(const int year) const;
				void				parseInput(const char *input) const;
				void				printValueTable(void) const;

	private:
				std::map<time_t, double>	_xChangeRate;
};
