/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:56:02 by sqiu              #+#    #+#             */
/*   Updated: 2024/03/29 14:49:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main(void){
	Data		pool;
	uintptr_t	serialized; 
	Data*		deserialized;
	
	pool.c = 'a';
	pool.n = 2;
	pool.you_good = true;
	pool.str = "yomomma";
	std::cout << "Data before serialization:\n";
	std::cout << "char: " << pool.c << "\n";
	std::cout << "int: " << pool.n << "\n";
	std::cout << "boolean: " << pool.you_good << "\n";
	std::cout << "string: " << pool.str << "\n";
	std::cout << "Data adress: " << &pool << "\n";

	serialized = Serializer::serialize(&pool);
	std::cout << "\nSerialized adress: " << serialized << "\n";
	
	deserialized = Serializer::deserialize(serialized);
	std::cout << "\nData after serialization:\n";
	std::cout << "char: " << deserialized->c << "\n";
	std::cout << "int: " << deserialized->n << "\n";
	std::cout << "boolean: " << deserialized->you_good << "\n";
	std::cout << "string: " << deserialized->str << "\n";
	std::cout << "Deserialized adress: " << deserialized << "\n";
	return 0;
}
