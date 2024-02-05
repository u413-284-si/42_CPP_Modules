/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:02:58 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/05 16:06:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include <iomanip>
#include <iostream>

#include "Contact.hpp"

/* ====== MACROS ====== */

# define NUM_CONTACTS 8

/* ====== CLASS DECLARATION ====== */

class PhoneBook{
	public:
				PhoneBook(void);
				~PhoneBook(void);

				void	start(void);
				void	processInput(void);
	private:
				Contact	mContactList[NUM_CONTACTS];
				int		mCurrentIndex;

				enum	eCommand{
						ADD,
						SEARCH,
						EXIT						
				};
				
				void		promptCommands(void);
				eCommand	parseCommand(std::string cmd);
				
}

#endif
