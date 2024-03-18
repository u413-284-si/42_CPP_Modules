/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:28:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 11:06:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include "Bureaucrat.hpp"

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class Form{
	public:
				Form(void);
				Form(const std::string& name, int gradeSign, int gradeExec);
				Form(const Form& other);
				virtual ~Form(void);

				Form&	operator=(const Form& rhs);

				const std::string&	getName(void) const;
				int					getGradeSign(void) const;
				int					getGradeExec(void) const;
				bool				getSigned(void) const;
				void				beSigned(const Bureaucrat& b);

				class GradeTooHighException : public std::exception{
					public:
							virtual const char* what() const throw();
				};

				class GradeTooLowException : public std::exception{
					public:
							virtual const char* what() const throw();
				};

	private:
				const std::string	_name;
				bool				_signed;
				const int			_gradeSign;
				const int			_gradeExec;
};

std::ostream&	operator<<(std::ostream& os, const Form& f);
