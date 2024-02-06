/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:02:58 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/06 10:29:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ====== LIBRARIES ====== */

#include <string>
#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "Contact.hpp"

/* ====== MACROS ====== */

# define NUM_CONTACTS 8

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
				Contact	mContactList[NUM_CONTACTS];
				int		mCurrentIndex;

				void	promptCommands(void) const;
				void	addContact(void);
				void	parseInput(const int field, std::string *input);
				void	searchContact(void) const;				
};

#endif
