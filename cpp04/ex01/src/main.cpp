/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:43:19 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/02 14:40:52 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

void	testSubject(void){
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	return;
}

void	testWrongAnimal(void){
	const WrongAnimal*	bubu = new WrongCat();
	WrongAnimal a;

	std::cout << bubu->getType() << std::endl;
	bubu->makeSound();
	std::cout << a.getType() << std::endl;
	a.makeSound();

	delete bubu;
	return;
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n" << std::endl;
	testSubject();
	std::cout << "\n* TEST WRONGCAT *\n" << std::endl;
	testWrongAnimal();
	return 0;	
}
