/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:07:12 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/07 23:33:19 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <list>

void	testSubject(void){
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return;	
}

void	testInsert(void){
	Span				sp(10);
	const static int	arr[] = {3, 9, 36, 2};
	std::list<int>		lst(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try{
		sp.insert(lst.begin(), lst.end());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::vector<int>	vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try{
		sp.insert(vec.begin(), vec.end());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	sp.printElements();
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	return;
}

void	testTooFewForSpan(void){
	Span	sp(1);

	std::cout << "\nTest 0 elements: \n";
	try{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nTest 1 element: \n";
	sp.addNumber(23);
	try{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	testOverfill(void){
	Span				sp(3);
	const static int	arr[] = {3, 9, 36, 2};
	std::list<int>		lst(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try{
		sp.insert(lst.begin(), lst.end());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(89);
	sp.addNumber(8);
	sp.addNumber(839);
	try{
		sp.addNumber(1);
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	sp.printElements();
	return;
}

void	testHard(const unsigned int size){
	Span	sp(size);
	
	try{
		for (unsigned int i = 0; i < size; i++)
			sp.addNumber(i);
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	return;
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n";
	testSubject();
	
	std::cout << "\n* TEST INSERT *\n";
	testInsert(); 

	std::cout << "\n* TEST TOO FEW ELEMENTS FOR SPAN *\n";
	testTooFewForSpan(); 

	std::cout << "\n* TEST OVERFILL *\n";
	testOverfill(); 

	std::cout << "\n* TEST HARD *\n";
	testHard(50000); 
	return 0;	
}
