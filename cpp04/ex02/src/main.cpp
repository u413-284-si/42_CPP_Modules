/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:43:19 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/08 12:42:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

void	testSubject(void){
	Animal*	animals[10];
	
	for (int i = 0; i < 5; i++){
		animals[i] = new Dog();
		animals[i + 5] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return;
}

void	testSubject2(void){
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	
	delete j;
	delete i;
	return;
}

void	testBrain(void){
	Brain	b1;
	Brain	b2;
	
	b1.setIdea("Yipppieee", 0);
	std::cout << "\n----- Brain 1 idea: -----\n";
	b1.printIdea(0);
	std::cout << "\tat " << &b1 << std::endl;
	std::cout << "\n----- Brain 2 idea: -----\n";
	b2.printIdea(0);
	std::cout << "\tat " << &b2 << std::endl;
	std::cout << "\n----- Copy assignment: -----\n";
	b2 = b1;
	std::cout << "\n----- Brain 1 idea: -----\n";
	b1.printIdea(0);
	std::cout << "\tat " << &b1 << std::endl;
	std::cout << "\n----- Brain 2 idea: -----\n";
	b2.printIdea(0);
	std::cout << "\tat " << &b2 << std::endl;
	return;	
}

void	testDog(void){
	Dog	d1;
	int	n1;

	d1.printIdeas();
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Foooood", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Scratch me!", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();
	return;
}

void	testCat(void){
	Cat	d1;
	int	n1;

	d1.printIdeas();
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Foooood", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Scratch me!", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();

	std::cout << "*** Copy assignment: ***\n\n";
	Cat d2;
	d2 = d1;
	d2.printIdeas();

	std::cout << "*** Copy construction: ***\n\n";
	Cat d3(d1);
	d3.printIdeas();
	return;
}

void	testDeepCopies(void){
	Dog	d1;
	Dog	d2;
	int	n1;
	
	std::cout << "----- Dog 1 ideas: -----\n";
	d1.printIdeas();
	std::cout << "----- Dog 2 ideas: -----\n";
	d2.printIdeas();
	
	std::cout << "*** Add ideas: ***\n\n";
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Foooood", i);
		d1.setLastIdea(i);
	}
	std::cout << "----- Dog 1 ideas: -----\n";
	d1.printIdeas();
	std::cout << "----- Dog 2 ideas: -----\n";
	d2.printIdeas();
	
	std::cout << "*** Copy assignment: ***\n\n";
	d2 = d1;
	std::cout << "----- Dog 1 ideas: -----\n";
	d1.printIdeas();
	std::cout << "----- Dog 2 ideas: -----\n";
	d2.printIdeas();

	std::cout << "*** Copy construction: ***\n\n";
	Dog	d3(d1);
	std::cout << "----- Dog 3 ideas: -----\n";
	d3.printIdeas();
	return;
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n" << std::endl;
	testSubject();
	std::cout << "\n* TEST SUBJECT2 *\n" << std::endl;
	testSubject2();
	std::cout << "\n* TEST BRAIN *\n" << std::endl;
	testBrain();
	std::cout << "\n* TEST DOG *\n" << std::endl;
	testDog();
	std::cout << "\n* TEST CAT *\n" << std::endl;
	testCat();
	std::cout << "\n* TEST DEEPCOPIES *\n" << std::endl;
	testDeepCopies();
	return 0;
}
