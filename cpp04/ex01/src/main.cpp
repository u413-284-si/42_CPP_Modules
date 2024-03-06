/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:43:19 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/06 18:18:24 by sqiu             ###   ########.fr       */
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

void	testDeepCopies(void){
	Dog	d1;
	int	n1;

	d1.printIdeas();
	std::cout << std::endl;
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Foooood", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();
	std::cout << std::endl;
	n1 = d1.getLastIdea();
	for (int i = n1 + 1; i < n1 + 4; i++){
		d1.setIdea("Scratch me!", i);
		d1.setLastIdea(i);
	}
	d1.printIdeas();
	std::cout << std::endl;
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n" << std::endl;
	testSubject();
	std::cout << "\n* TEST SUBJECT2 *\n" << std::endl;
	testSubject2();
	std::cout << "\n* TEST DEEPCOPIES *\n" << std::endl;
	testDeepCopies();
	return 0;
}
