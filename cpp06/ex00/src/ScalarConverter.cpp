/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:31 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/27 18:57:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int		ScalarConverter::_i = 0;
char	ScalarConverter::_c = '\0';
float	ScalarConverter::_f = 0.0f;
double	ScalarConverter::_d = 0.0;

/* CONSTRUCTORS */

ScalarConverter::ScalarConverter(void){return;}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	*this = other;
	return;
}

ScalarConverter::~ScalarConverter(void){return;}

/* EXCEPTIONS */

const char* ScalarConverter::NotDisplayableExceptioin::what() const throw(){
	return "input exception: non printable char found";
}

const char* ScalarConverter::InvalidInputExceptioin::what() const throw(){
	return "input exception: invalid format. conversion failed";
}

/* OPERATOR OVERLOADING */

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs){
	(void)rhs;
	return *this;
}

/* MEMBER FUNCTIONS */

bool	ScalarConverter::findNonPrintable(std::string str){
	for (std::string::iterator i = str.begin(); i != str.end(); i++){
		if (*i < 32 || *i > 126)
			return true;
	}
	return false;
}

e_type	ScalarConverter::getType(const std::string& str){
	char	*endptr;
	double	n = strtod(str.c_str(), &endptr);
	size_t	lenRemainder = std::strlen(endptr);

	if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		return NINF;
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return NOTANUM;
	if (str.empty() || str == endptr || (*endptr != '\0' && (*endptr != 'f'\
		|| lenRemainder > 1)))
		throw InvalidInputExceptioin();
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;
	if (str.find('.') == std::string::npos && *endptr != 'f' \
		&& n <= std::numeric_limits<int>::max() \
		&& n >= std::numeric_limits<int>::min())
		return INT;
	if (*endptr == 'f')
		return FLOAT;
	else
		return DOUBLE;
}

void	ScalarConverter::printVars(const e_type& type, const std::string& str){
	switch(type){
	case CHAR:{
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		break;
	}
	case INT:{
		int	n = atoi(str.c_str());
		
		if (n > std::numeric_limits<unsigned char>::max() \
			|| n < std::numeric_limits<unsigned char>::min())
			std::cout << "char: impossible" << std::endl;
		else if (n > 126 || n < 32)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<unsigned char>(n) << "'" << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
		break;
	}
	case FLOAT:{
		float	n = strtof(str.c_str(), NULL);
		
		if (n > std::numeric_limits<unsigned char>::max() \
			|| n < std::numeric_limits<unsigned char>::min())
			std::cout << "char: impossible" << std::endl;
		else if (n > 126 || n < 32)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<unsigned char>(n) << "'" << std::endl;
		if (n > std::numeric_limits<int>::max() \
			|| n < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << n << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
		break;
	}
	case DOUBLE:{
		double	n = strtod(str.c_str(), NULL);

		if (n > std::numeric_limits<unsigned char>::max() \
			|| n < std::numeric_limits<unsigned char>::min())
			std::cout << "char: impossible" << std::endl;
		else if (n > 126 || n < 32)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<unsigned char>(n) << "'" << std::endl;
		if (n > std::numeric_limits<int>::max() \
			|| n < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;
		std::cout.precision(1);
		if (isinf(n))
			std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
		else if (n > std::numeric_limits<float>::max() \
			|| n < std::numeric_limits<float>::min())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << n << std::endl;
		break;			
	}
	case NINF:{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		break;
	}
	case NOTANUM:{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	}
	}
	return;
} 

void	ScalarConverter::convert(const std::string& str){
	try{
		if (findNonPrintable(str))
			throw NotDisplayableExceptioin();
		e_type type = getType(str);
		printVars(type, str);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return;
}
