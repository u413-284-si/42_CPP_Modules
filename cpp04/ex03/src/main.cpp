/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:48:38 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/11 15:40:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"

void	testSubject(void){
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	testCharacter(void){
	ICharacter*	dude = new Character("Jamal");
	ICharacter*	dudette = new Character("Teesha");
	AMateria*	cure1 = new Cure();
	AMateria*	cure2 = new Cure();
	AMateria*	ice1 = new Ice();

	dude->use(1, *dudette);
	
	dude->equip(new Cure());
	dude->equip(new Ice());
	dude->equip(new Ice());
	dude->equip(cure1);
	dude->equip(cure2);
	dude->equip(ice1);
	
	dude->use(0, *dudette);
	dude->use(1, *dudette);
	dude->use(2, *dudette);
	dude->use(3, *dudette);
	
	dude->unequip(3);
	dude->use(3, *dudette);
	dude->equip(new Cure());
	dude->use(3, *dudette);

	AMateria * materia = dude->getMateria(0);
	dude->unequip(0);
	dude->use(0, *dudette);
	dude->equip(new Cure());
	dude->use(0, *dudette);

	delete materia;
	delete cure1;
	delete dudette;
	delete dude;
	return;
}

void	testMateriaSource(void){
	//IMateriaSource*	src1 = new MateriaSource();
}

int	main(void){
	std::cout << "\n* TEST SUBJECT *\n" << std::endl;
	testSubject();
	std::cout << "\n* TEST CHARACTER *\n" << std::endl;
	testCharacter();
	std::cout << "\n* TEST MATERIASOURCE *\n" << std::endl;
	testMateriaSource();
	return 0;
}
