/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:18:50 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/29 18:00:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include <time.h>
#include <cstdlib>

Base	*generate(void){
	srand(time(0));
	int	n = rand() % 3;
	
	// implicit upcasting of return values
	if (n == 0)
		return new A();
	else if (n == 1)
		return new B();
	else
		return new C();
}

/* 
	Dynamic cast returns NULL if conversion was not succesfull
*/
void	identify(Base *p){
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Actual object is: A" << std::endl;
	else if (b)	
		std::cout << "Actual object is: B" << std::endl;
	else if (c)
		std::cout << "Actual object is: C" << std::endl;
	else
		std::cout << "Actual object is: unidentified" << std::endl;
	return;
}


void	identify(Base& p){
	try{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Actual object is: A" << std::endl;
	}
	catch (std::exception& bc){
		std::cerr << "Object not of type 'A': " << bc.what() << std::endl;
	}
	try{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Actual object is: B" << std::endl;
	}
	catch (std::exception& bc){
		std::cerr << "Object not of type 'B': " << bc.what() << std::endl;
	}	
	try{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Actual object is: C" << std::endl;
	}
	catch (std::exception& bc){
		std::cerr << "Object not of type 'C': " << bc.what() << std::endl;
	}
	return;
}

int	main(void){
	Base	*ptr;

	ptr = generate();
	std::cout << "* Identifying with pointers *\n";
	identify(ptr);
	std::cout << "\n* Identifying with pointers *\n";
	identify(*ptr);
	return 0;
}
