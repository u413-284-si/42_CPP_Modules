/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:31:26 by sqiu              #+#    #+#             */
/*   Updated: 2024/04/05 15:02:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include "../inc/print.hpp"

#define ARR_SIZE 3
int	main(void){
	int			arr_int[ARR_SIZE] = {1, 2, 3};
	float		arr_float[ARR_SIZE] = {1.231f, 2.244f, 3.363f};
	double		arr_double[ARR_SIZE] = {1.221, 2.233, 3.354};
	std::string	arr_str[ARR_SIZE] = {"oans", "zwo", "dree"};
	const char	*arr_strC[ARR_SIZE] = {"un", "deux", "trois"};
	char		arr_char[ARR_SIZE] = {'e', 't', '3'};

	iter(arr_int, ARR_SIZE, &print);
	std::cout << std::endl;
	iter(arr_float, ARR_SIZE, &print);
	std::cout << std::endl;
	iter(arr_double, ARR_SIZE, &print);
	std::cout << std::endl;
	iter(arr_str, ARR_SIZE, &print);
	std::cout << std::endl;
	iter(arr_strC, ARR_SIZE, &print);
	std::cout << std::endl;
	iter(arr_char, ARR_SIZE, &print);
	return 0;
}
