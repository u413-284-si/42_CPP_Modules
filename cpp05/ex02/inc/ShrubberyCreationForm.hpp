/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:39:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/14 18:56:44 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class ShrubberyCreationForm : public AForm{
	public:
				ShrubberyCreationForm(void);
				ShrubberyCreationForm(const std::string& target);
				ShrubberyCreationForm(const ShrubberyCreationForm& other);
				virtual ~ShrubberyCreationForm(void);

				ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
				
				void	execute(const Bureaucrat& executor) const;
	private:
				const std::string	_target;
};
