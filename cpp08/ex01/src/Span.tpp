/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:51:04 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 12:50:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	Span::insert(T first, T last){
	unsigned int	dist = std::distance(first, last);
	if (this->_occupancy + dist > this->_N)
		throw std::runtime_error("error: container full");
	this->_vec.insert(this->_vec.end(), first, last);
	this->_occupancy += dist;
	return;	
}
