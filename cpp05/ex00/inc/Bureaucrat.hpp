/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:12:18 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/13 00:04:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class Bureaucrat{
		public:
					Bureaucrat(void);
					Bureaucrat(const std::string& name, int grade);
					Bureaucrat(const Bureaucrat& other);
					virtual ~Bureaucrat(void);

					Bureaucrat&			operator=(const Bureaucrat& rhs);
					
					const std::string&	getName(void) const;
					int					getGrade(void) const;
					void				incrGrade(void);
					void				decrGrade(void);

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
					int					_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);
