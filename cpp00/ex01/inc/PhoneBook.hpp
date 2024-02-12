/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:02:58 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/12 17:58:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include <iomanip>
#include <iostream>
#include <unistd.h>		//sleep
#include <cstdlib>		//atoi

#include "Contact.hpp"

/* ====== MACROS ====== */

# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10

// Text effects
# define CLRSCR "\033[2J\033[1;1H"
# define RESET "\033[0m"
# define BOLD "\033[1m"

// Colours
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

/* ====== CLASS DECLARATION ====== */

class PhoneBook{
	public:
				PhoneBook(void);
				~PhoneBook(void);

				void	start(void);
				void	processInput(void);
	private:
				Contact	mContactList[MAX_CONTACTS];
				int		mCurrentIndex;
				int		mNumContacts;

				void		promptCommands(void) const;
				
				// ADD CONTACT
				void		addContact(void);
				void		parseInput(const int field, std::string *input);

				// SEARCH CONTACT
				void		searchContact(void) const;			
				void		promptContact(void) const;

				// CREATE CONTACT TABLE
				void		displayContacts(void) const;
				void		displayTitleRow(void) const;
				void		displayContactRow(const int i) const;
				void		createColumn(void) const;
				std::size_t	getStrLenUtf8(const std::string& str) const;
				std::string	truncateData(const std::string& data) const;
};

#endif
