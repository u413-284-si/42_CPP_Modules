/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:39:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/15 13:05:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ====== LIBRARIES ====== */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ====== DEFINITIONS ====== */

/* ====== CLASS DECLARATION ====== */

class PresidentialPardonForm : public AForm{
	public:
				PresidentialPardonForm(void);
				PresidentialPardonForm(const std::string& target);
				PresidentialPardonForm(const PresidentialPardonForm& other);
				virtual ~PresidentialPardonForm(void);

				PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
				
				void	execute(const Bureaucrat& executor) const;
	private:
				const std::string	_target;
};
