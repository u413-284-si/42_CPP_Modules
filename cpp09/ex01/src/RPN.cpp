/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:41:35 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/19 15:49:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

/* CONSTRUCTORS */

RPN::RPN(void){
	if (VERBOSE)
		std::cout << "[RPN]: DEFAULT CONSTRUCTOR CALLED" << std::endl;
	return;
}

RPN::RPN(const RPN& other){
	if (VERBOSE)
		std::cout << "[RPN]: COPY CONSTRUCTOR CALLED" << std::endl;
	*this = other;
	return;
}

RPN::~RPN(void){
	if (VERBOSE)
		std::cout << "[RPN]: DESTRUCTOR CALLED" << std::endl;
	return;
}

/* OPERATOR OVERLOADING */

RPN&	RPN::operator=(const RPN& rhs){
	if (VERBOSE)
		std::cout << "[RPN]: ASSIGNMENT OPERATOR CALLED" << std::endl;
	if (this != &rhs)
		this->_st = rhs._st;
	return *this;
}

/* MEMBER FUNCTIONS */

void	RPN::parseInput(const std::string input){
	if (input.empty())
		throw std::invalid_argument("input is empty");
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("non supported character given");
	for (std::string::const_iterator cit = input.begin(); cit != input.end(); cit++){
		if (*cit == ' ')
			continue;
		else if (std::isdigit(*cit)){
			if (*(cit + 1) != ' ')
				throw std::invalid_argument("a digit must be followed by ' '");
			this->_st.push(*cit - '0');
		}
		else{
			if (this->_st.size() < 2)
				throw std::runtime_error("not enough numbers for calculation");
			if (*(cit + 1) != ' ' && *(cit + 1) != '\0')
				throw std::invalid_argument("an operator must be followed by ' ' or '\0'");
			doTheMaths(cit);
		}
	}
	if (this->_st.size() != 1)
		throw std::invalid_argument("operator missing");
	return;
}

void	RPN::doTheMaths(const std::string::const_iterator& cit){
	long	operand, tmp;
	
	operand = this->_st.top();
	this->_st.pop();
	tmp = this->_st.top();
	switch (*cit){
		case '+':
			if (tmp + operand > std::numeric_limits<int>::max()\
				|| tmp + operand < std::numeric_limits<int>::min())
				throw std::runtime_error("integer overflow");
			this->_st.top() += operand;
			break;
		case '-':
			if (tmp - operand > std::numeric_limits<int>::max()\
				|| tmp - operand < std::numeric_limits<int>::min())
				throw std::runtime_error("integer overflow");
			this->_st.top() -= operand;
			break;
		case '*':
			if (tmp * operand > std::numeric_limits<int>::max()\
				|| tmp * operand < std::numeric_limits<int>::min())
				throw std::runtime_error("integer overflow");
			this->_st.top() *= operand;
			break;
		case '/':
			if (operand == 0)
				throw std::runtime_error("no division by zero allowed");
			this->_st.top() /= operand;
			break;
	}
	return;
}

int		RPN::getResult(void){
	int	result;
	
	if (this->_st.size() < 1)
		throw std::runtime_error("no elements stored");
	result = this->_st.top();
	return result;
}
