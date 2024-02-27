/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/27 17:05:52 by sqiu             ###   ########.fr       */
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
				
				float	getmX(void) const;
				float	getmY(void) const;
				float	sign2DCrossProduct(const Point& a, const Point& b, const Point& p) const;
	
	private:
				const Fixed mX;
				const Fixed mY;
};

#endif
