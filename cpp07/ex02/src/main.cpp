#include <iostream>
#include <Array.hpp>

# define ARR_SIZE 5

template <typename T>
void	testEmpty(const std::string& type){
	std::cout << "\nTesting for <" << type << ">\n";
	std::cout << "-----------------------------------\n";
	Array<T>	arr;

	std::cout << "Trying to access elements\n";
	try{
		std::cout << arr[0] << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

template <typename T>
void	testConstructors(const std::string& type, const unsigned int size){
	std::cout << "\nTesting for <" << type << ">\n";
	std::cout << "-----------------------------------\n";
	Array<T>	arr(size);

	srand(time(0));
	for (unsigned int i = 0; i < size; i++){
		arr[i] = rand();
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	std::cout << "\nCreating copy\n";
	Array<T>	copy(arr);
	for (unsigned int i = 0; i < size; i++){
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
	}
	std::cout << "\nChanging copy\n";
	for (unsigned int i = 0; i < size; i++){
		copy[i] = rand();
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
	}
	std::cout << "\nOriginal array\n";
	for (unsigned int i = 0; i < size; i++){
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	std::cout << "\nCreating empty array\n";
	Array<T>	empty;
	std::cout << "\nAssigning copy on empty array\n";
	empty = copy;
	for (unsigned int i = 0; i < size; i++){
			std::cout << "empty[" << i << "] = " << empty[i] << std::endl;
	}
	return;
}

template <typename T>
void	testOutOfRange(const std::string& type, unsigned int size){
	std::cout << "\nTesting for <" << type << ">\n";
	std::cout << "-----------------------------------\n";
	Array<T>	arr(size);

	std::cout << "\nTesting out of range: lower end\n";
	try{
		arr[-1];
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nTesting out of range: upper end\n";
	try{
		arr[size];
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

template <typename T>
void	testConst(const std::string& type, unsigned int size){
	std::cout << "\nTesting for <" << type << ">\n";
	std::cout << "-----------------------------------\n";
	Array<T>		arr(size);
	srand(time(0));
	for (unsigned int i = 0; i < size; i++){
		arr[i] = rand();
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	std::cout << "\nCreating const array\n";
	const Array<T>	carr(arr);
	for (unsigned int i = 0; i < size; i++){
		//carr[i] = 1;
		std::cout << "carr[" << i << "] = " << carr[i] << std::endl;
	}
	return;
}

int	main(void){
	std::cout << "\n* EMPTY ARRAY TESTS *\n";
	testEmpty<int>("int");
	testEmpty<float>("float");
	testEmpty<std::string>("string");

	std::cout << "\n* NUMBER ARRAY TESTS *\n";
	testConstructors<int>("int", ARR_SIZE);
	testConstructors<float>("float", ARR_SIZE);
	testConstructors<double>("double", ARR_SIZE);

	std::cout << "\n* OUT OF RANGE TESTS *\n";
	testOutOfRange<int>("int", ARR_SIZE);
	testOutOfRange<float>("float", ARR_SIZE);
	testOutOfRange<char>("char", ARR_SIZE);

	std::cout << "\n* CONST ARRAY TESTS *\n";
	testConst<int>("int", ARR_SIZE);
	testConst<float>("float", ARR_SIZE);
	testConst<double>("double", ARR_SIZE);
	return 0;
}



// SUBJECT MAIN
/* #define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
 */