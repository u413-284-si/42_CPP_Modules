/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:22:59 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 12:56:48 by sqiu             ###   ########.fr       */
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
				~Fixed(void);

				Fixed&	operator=(const Fixed& rhs);
				bool	operator>(const Fixed& rhs) const;
				bool	operator<(const Fixed& rhs) const;
				bool	operator>=(const Fixed& rhs) const;
				bool	operator<=(const Fixed& rhs) const;
				bool	operator==(const Fixed& rhs) const;
				bool	operator!=(const Fixed& rhs) const;

				Fixed	operator+(const Fixed& rhs) const;
				Fixed	operator-(const Fixed& rhs) const;
				Fixed	operator*(const Fixed& rhs) const;
				Fixed	operator/(const Fixed& rhs) const;

				Fixed&	operator++(void);
				Fixed	operator++(int);
				Fixed&	operator--(void);
				Fixed	operator--(int);

				static Fixed&		min(Fixed& a, Fixed& b);
				static Fixed&		max(Fixed& a, Fixed& b);

				const static Fixed&	min(const Fixed& a, const Fixed& b);
				const static Fixed&	max(const Fixed& a, const Fixed& b);

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
