/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:22:59 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/26 21:54:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* ====== LIBRARIES ====== */

#include <iostream>

/* ====== CLASS DECLARATION ====== */

class Fixed{
	public:
				Fixed(void);
				Fixed(const Fixed& other);
				Fixed& operator= (const Fixed& rhs);
				~Fixed(void);

				int		getRawBits(void) const;
				void	setRawBits(int const raw);
				
	private:
				int	mFixedValue;
				const static int	msFracBits = 8;
};

#endif
