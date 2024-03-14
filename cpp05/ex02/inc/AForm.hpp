/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:28:47 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/13 01:12:14 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include "Bureaucrat.hpp"

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class AForm{
	public:
				AForm(void);
				AForm(const std::string& name, int gradeSign, int gradeExec);
				AForm(const AForm& other);
				virtual ~AForm(void);

				AForm&	operator=(const AForm& rhs);

				const std::string&	getName(void) const;
				int					getGradeSign(void) const;
				int					getGradeExec(void) const;
				bool				getSigned(void) const;
				void				beSigned(const Bureaucrat& b);
				virtual void		execute(const Bureaucrat& executor) const = 0;
				void				checkExec(const Bureaucrat& executor) const;

				class GradeTooHighException : public std::exception{
						public:
								virtual const char* what() const throw(){
									return "Form exception: grade too high.";
								}
					};

				class GradeTooLowException : public std::exception{
					public:
							virtual const char* what() const throw(){
								return "Form exception: grade too low.";
							}
				};

				class FormNotSignedException : public std::exception{
					public:
							virtual const char* what() const throw(){
								return "Form exception: not signed.";
							}
				};

	private:
				const std::string	_name;
				bool				_signed;
				const int			_gradeSign;
				const int			_gradeExec;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);
