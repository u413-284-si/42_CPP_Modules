/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:37:32 by sqiu              #+#    #+#             */
/*   Updated: 2024/05/17 12:17:13 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <cstring>

// Function to convert std::vector<std::string> to char**
char** convertToCharArray(const std::vector<std::string>& vec) {
    size_t numStrings = vec.size();
    size_t i;
    // Allocate memory for the array of char* pointers
    char** charArray = new char*[numStrings + 1];

    for (i = 0; i < numStrings; ++i) {
        // Allocate memory for each string (+1 for the null terminator)
        charArray[i] = new char[vec[i].size() + 1];
        
        // Copy the content of the std::string to the char* array
        std::strcpy(charArray[i], vec[i].c_str());
    }
	charArray[i] = NULL;
    return charArray;
}

// Function to free the allocated memory
void freeCharArray(char** charArray, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        delete[] charArray[i];
    }
    delete[] charArray;
	return;
}

void	runTests(const std::string& name, size_t total, const std::pair<std::vector<std::string>, int> tests[]){

	std::cout << "\n* " << name << " *\n";
	for (size_t i = 0; i < total; i++){
		std::cout << "\nTest [" << i << "]:\nMax. comparisons: " << tests[i].second << std::endl;
		{
			PmergeMe	p;
			char		**testArr = convertToCharArray(tests[i].first);
			try{
					p.checkInput(testArr);
			}
			catch(std::exception& e){
				std::cout << RED << "Error: " << e.what() << RESET << std::endl;
			}
			// Check handling with vector
			if (p.handleInputWithVector(testArr) > tests[i].second){
				std::cerr << YELLOW << "Warning: More comparisons required than stipulated by theory\n" << RESET;
			}
			std::vector<int>	tmpVector = p.getVector();
			if (std::is_sorted(tmpVector.begin(), tmpVector.end()))
				std::cout << GREEN << "\nSUCCESS!\n" << RESET << std::endl;
			else
				std::cerr << RED << "\nFAILURE - numbers are not sorted\n" << RESET;

			// Check handling with deque
			if (p.handleInputWithDeque(testArr) > tests[i].second){
				std::cerr << YELLOW << "Warning: More comparisons required than stipulated by theory\n";
			}
			std::deque<int>	tmpDeque = p.getDeque();
			if (std::is_sorted(tmpDeque.begin(), tmpDeque.end()))
				std::cout << GREEN << "\nSUCCESS!\n" << RESET << std::endl;
			else
				std::cerr << RED << "\nFAILURE - numbers are not sorted\n" << RESET;
			freeCharArray(testArr, tests[i].first.size());	
		}
	}
	return;
}

void	testValid(void){
	std::pair<std::vector<std::string>, int>	tests[] = {
		std::make_pair(std::vector<std::string>{"prog", "1"}, 0),
		std::make_pair(std::vector<std::string>{"prog", "1", "3"}, 1),
		std::make_pair(std::vector<std::string>{"prog", "3", "1"}, 1),
		std::make_pair(std::vector<std::string>{"prog", "125", "35"}, 1),
		std::make_pair(std::vector<std::string>{"prog", "1", "1"}, 1),
		std::make_pair(std::vector<std::string>{"prog", "1", "5", "3"}, 3),
		std::make_pair(std::vector<std::string>{"prog", "19", "5", "3"}, 3),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "35"}, 3),
		std::make_pair(std::vector<std::string>{"prog", "1", "5", "3", "9"}, 5),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3"}, 5),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "0"}, 7),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "7", "9"}, 10),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123"}, 13),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88"}, 16),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25"}, 19),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7"}, 22),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79"}, 26),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98"}, 30),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99"}, 34),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99", "56"}, 38),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99", "89", "311"}, 42),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99", "89", "311", "4", "142", "39", "356", "31"}, 62),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99", "89", "311", "4", "142", "39", "356", "31", "96"}, 66),
		std::make_pair(std::vector<std::string>{"prog", "12", "5", "43", "3", "78", "1", "123", "88", "25", "7", "79", "98", "99", "89", "311", "4", "142", "39", "356", "31", "96", "45"}, 71),
	};
	runTests("VALID TEST CASES", sizeof(tests) / sizeof(tests[0]), tests);
	return;
}

int	main(void){
	testValid();
	return 0;
}
