/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:39:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 12:52:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class RobotomyRequestForm : public AForm{
	public:
				RobotomyRequestForm(void);
				RobotomyRequestForm(const std::string& target);
				RobotomyRequestForm(const RobotomyRequestForm& other);
				virtual ~RobotomyRequestForm(void);

				RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
				
				void	execute(const Bureaucrat& executor) const;
	private:
				const std::string	_target;
};
