/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:58:26 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 00:11:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

template <typename T>
void	testElement(const T container, const int n){
	typename T::const_iterator	it;
	
	try{
		it = easyfind(container, n);
		std::cout << "Element <"<< *it <<"> found!" << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	testList(void){
	const static int arr[] = {1, 2, 3, 4, 5};
	{
		std::cout << "\nTesting for mutable list:";
		std::list<int>	lst;

		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		std::cout << "\nTesting for existing element:\n";
		testElement(lst, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(lst, 7);
	}
	{
		std::cout << "\nTesting for constant list:";
		/* constructs a pair of iterators pointing to the beginning and
		just past the end of the array arr, effectively specifying a range. */
		const std::list<int>	clst(arr, arr + sizeof(arr) / sizeof(arr[0]));

		std::cout << "\nTesting for existing element:\n";
		testElement(clst, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(clst, 7);
	}
	{
		std::cout << "\nTesting for empty list:\n";
		std::list<int>	lst;

		testElement(lst, 7);
	}
	return;
}

void	testVector(void){
	const static int arr[] = {1, 2, 3, 4, 5};
	{
		std::cout << "\nTesting for mutable vector:";
		std::vector<int>	vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::cout << "\nTesting for existing element:\n";
		testElement(vec, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(vec, 7);
	}
	{
		std::cout << "\nTesting for constant vector:";
		const std::vector<int>	cvec(arr, arr + sizeof(arr) / sizeof(arr[0]));

		std::cout << "\nTesting for existing element:\n";
		testElement(cvec, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(cvec, 7);
	}
	{
		std::cout << "\nTesting for empty vector:\n";
		std::vector<int>	vec;

		testElement(vec, 7);
	}
	return;
}

void	testDeque(void){
	const static int arr[] = {1, 2, 3, 4, 5};
	{
		std::cout << "\nTesting for mutable deque:";
		std::deque<int>	deque;

		deque.push_back(1);
		deque.push_back(2);
		deque.push_back(3);
		deque.push_back(4);
		deque.push_back(5);
		std::cout << "\nTesting for existing element:\n";
		testElement(deque, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(deque, 7);
	}
	{
		std::cout << "\nTesting for constant deque:";
		const std::deque<int>	cdeque(arr, arr + sizeof(arr) / sizeof(arr[0]));

		std::cout << "\nTesting for existing element:\n";
		testElement(cdeque, 3);
		std::cout << "Testing for non-existing element:\n";
		testElement(cdeque, 7);
	}
	{
		std::cout << "\nTesting for empty deque:\n";
		std::deque<int>	deque;

		testElement(deque, 7);
	}
	return;
}

int	main(void){
	std::cout << "\n* TEST LIST *\n";
	testList();
	
	std::cout << "\n* TEST VECTOR *\n";
	testVector();
	
	std::cout << "\n* TEST DEQUE *\n";
	testDeque();
	return 0;
}
