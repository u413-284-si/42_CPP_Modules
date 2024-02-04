/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:58:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/04 17:11:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

/* ====== LIBRARIES ====== */

#include <string>

/* ====== CLASS DECLARATION ====== */

class Contact{
	public:
				Contact(void);
				~Contact(void);

				std::string	getFirstName(void) const;
				std::string getLastName(void) const;
				std::string getNickname(void) const;
				std::string getPhoneNumber(void) const;
				std::string getDarkestSecret(void) const;
				void		getContactData(void) const;
				void		setFirstName(std::string firstName);
				void		setLastName(std::string lastName);
				void		setNickname(std::string nickname);
				void		setPhoneNumber(std::string phoneNumber);
				void		setDarkestSecret(std::string darkestSecret);
				void		setContactData(std::string firstName, \
										   std::string lastName, \
										   std::string nickname, \
										   std::string phoneNumber, \
										   std::string darkestSecret);
			
	private:
				std::string	mFirstName;
				std::string	mLastName;
				std::string mNickname;
				std::string	mPhoneNumber;
				std::string mDarkestSecret;
};

#endif
