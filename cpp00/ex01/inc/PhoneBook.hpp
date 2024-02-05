/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:02:58 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/05 18:04:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>	//std::all_of

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

				void	promptCommands(void) const;
				void	addContact(void);
				void	parseInput(const Contact::eFields field,
								   std::string	input);
				void	searchContact(void) const;				
}

#endif
