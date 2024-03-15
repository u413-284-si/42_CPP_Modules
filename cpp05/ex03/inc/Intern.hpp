/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:38:52 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 19:29:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <AForm.hpp>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ====== DEFINITIONS ====== */

# define VERBOSE 1

/* ====== CLASS DECLARATION ====== */

class Intern{
		public:
					Intern(void);
					Intern(const Intern& other);
					virtual ~Intern(void);

					Intern&	operator=(const Intern& rhs);
					
					AForm*	makeForm(const std::string formName, const std::string target) const;
					int		convertForm(const std::string formName) const;

					class WrongFormException : public std::exception{
					public:
							virtual const char* what() const throw(){
								return "form exception: not existent.";
							}
					};
};
