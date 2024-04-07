/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:07:12 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 12:34:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <list>

int	main(void){
	Span				s(10);
	const static int	arr[] = {3, 9, 36, 2};
	std::list<int>		lst(arr, arr + sizeof(arr) / sizeof(arr[0]));

	/* std::list<int>::iterator	it;
	for (it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl; */
	try{
		s.insert(lst.begin(), lst.end());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	s.addNumber(89);
	s.printElements();
	return 0;	
}
