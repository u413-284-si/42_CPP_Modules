/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:22:59 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/26 22:35:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* ====== LIBRARIES ====== */

#include <iostream>
#include <cmath>

/* ====== CLASS DECLARATION ====== */

class Fixed{
	public:
				Fixed(void);
				Fixed(const int num);
				Fixed(const float num);
				Fixed(const Fixed& other);
				Fixed& operator=(const Fixed& rhs);
				~Fixed(void);

				int		getRawBits(void) const;
				void	setRawBits(int const raw);
				float	toFloat(void) const;
				int		toInt(void) const;				
				
	private:
				int	mFixedValue;
				const static int	msFracBits = 8;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
