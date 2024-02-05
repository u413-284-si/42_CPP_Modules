/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:58:55 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/05 17:41:09 by sqiu             ###   ########.fr       */
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

				enum	eFields{
						FirstName,
						LastName,
						Nickname,
						PhoneNumber,
						DarkestSecret					
				};

				std::string	getFirstName(void) const;
				std::string getLastName(void) const;
				std::string getNickname(void) const;
				std::string getPhoneNumber(void) const;
				std::string getDarkestSecret(void) const;
				void		getContactData(void) const;
				void		setFirstName(const std::string& firstName);
				void		setLastName(const std::string& lastName);
				void		setNickname(const std::string& nickname);
				void		setPhoneNumber(const std::string& phoneNumber);
				void		setDarkestSecret(const std::string& darkestSecret);
				void		setContactData(const std::string& firstName, \
										   const std::string& lastName, \
										   const std::string& nickname, \
										   const std::string& phoneNumber, \
										   const std::string& darkestSecret);
			
	private:
				std::string	mFirstName;
				std::string	mLastName;
				std::string mNickname;
				std::string	mPhoneNumber;
				std::string mDarkestSecret;
};

#endif
