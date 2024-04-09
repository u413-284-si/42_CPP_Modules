/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:01 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/08 17:10:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <stdexcept>


/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class BitcoinExchange{
	public:
				BitcoinExchange(void);
				BitcoinExchange(const BitcoinExchange& other);
				~BitcoinExchange(void);

				BitcoinExchange&	operator=(const BitcoinExchange& rhs);

				int					checkLine(const std::string& line, time_t& date, double& rate);
				int					checkHeader(const std::string& line);
				void				parseInput(const char *input) const;
				void				printValueTable(void) const;

	private:
				std::map<time_t, double>	_xChangeRate;
};
