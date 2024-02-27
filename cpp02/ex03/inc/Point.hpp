/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 16:06:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

/* ====== LIBRARIES ====== */

#include "../inc/Fixed.hpp"

/* ====== CLASS DECLARATION ====== */

class Point{
	public:
				Point(void);
				Point(const float& m, const float& n);
				Point(const Point& other);
				~Point(void);

				Point&	operator=(const Point& rhs);
				
				Fixed	getmX(void) const;
				Fixed	getmY(void) const;
	
	private:
				const Fixed mX;
				const Fixed mY;
};

#endif
