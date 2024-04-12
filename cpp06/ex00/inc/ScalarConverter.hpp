/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:28:08 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/27 19:40:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cmath>
#include <cstdlib>

/* ====== DEFINITIONS ====== */

enum e_type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NINF,
	NOTANUM
};

/* ====== CLASS DECLARATION ====== */

class ScalarConverter{
	public:
				static void		convert(const std::string& str);
				static e_type	getType(const std::string& str);
				static void		printVars(const e_type& type, \
										const std::string& str);
				static bool		findNonPrintable(std::string str);

				class NotDisplayableException : public std::exception{
					public:
								virtual const char*	what() const throw();
				};
				
				class InvalidInputException : public std::exception{
					public:
								virtual const char*	what() const throw();
				};
	
	private:
				ScalarConverter(void);
				ScalarConverter(const ScalarConverter& other);
				~ScalarConverter(void);
				
				ScalarConverter&	operator=(const ScalarConverter& rhs);
};
