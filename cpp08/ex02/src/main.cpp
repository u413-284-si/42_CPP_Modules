/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:09:24 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/08 12:51:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <vector>

void	testSubject(void){
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while(it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int>	s(mstack);
	return;
}

void	testSubjectVector(void){
	std::vector<int>	vec;

	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);
	
	std::vector<int>::iterator	it = vec.begin();
	std::vector<int>::iterator	ite = vec.end();

	++it;
	--it;
	while(it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::vector<int>	s(vec);
	return;
}

void	testIterator(void){
	MutantStack<int>	mstack;
	
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "Increase value via iterator:\n";
	it -= mstack.size();
	while (it != ite){
		*it += 1;
		std::cout << *it << std::endl;
		it++;
	}
	return;
}

void	testConst(void){
	MutantStack<int>	mstack;
	
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::const_iterator	it = mstack.cbegin();
	MutantStack<int>::const_iterator	ite = mstack.cend();
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	return;
}

void	testReverse(void){
	MutantStack<int>	mstack;
	
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack.rend();
	while (rit != rite){
		std::cout << *rit << std::endl;
		rit++;
	}
	std::cout << "Increase value via iterator:\n";
	rit -= mstack.size();
	while (rit != rite){
		*rit += 1;
		std::cout << *rit << std::endl;
		rit++;
	}
	return;
}

void	testConstReverse(void){
	MutantStack<int>	mstack;
	
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::const_reverse_iterator	crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator	crite = mstack.crend();
	while (crit != crite){
		std::cout << *crit << std::endl;
		crit++;
	}
	return;
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n";
	testSubject();	

	std::cout << "\n* TEST SUBJECT VECTOR*\n";
	testSubjectVector();	

	std::cout << "\n* TEST ITERATOR *\n";
	testIterator();
	
	std::cout << "\n* TEST CONST ITERATOR *\n";
	testConst();

	std::cout << "\n* TEST REVERSE ITERATOR *\n";
	testReverse();

	std::cout << "\n* TEST CONST REVERSE ITERATOR *\n";
	testConstReverse();
	return 0;
}
