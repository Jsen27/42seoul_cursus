#include "PmergeMe.hpp"

void printVector(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

bool validateInput(std::string s)
{
	char *ptr = NULL;
	double value = std::strtod(s.c_str(), &ptr);

	if (value == 0.0 && !std::isdigit(s[0]))
		return false;
	if (*ptr && std::strcmp(ptr, "f"))
		return false;
	if (value < 0)
		return false;
	return (value == static_cast<int>(value));
}

int main(int argc, char** argv)
{
	if (argc < 2){
		std::cout << "Usage: ./PmergeMe \"number\"" << std::endl;
		return -1;
	}

	std::vector<int> vec;
	
	for (int i = 1; i < argc; i++){
		std::stringstream ss;
		std::string tmp;
		ss << argv[i];
		while (std::getline(ss, tmp, ' ')){
			if (!tmp.empty() && validateInput(tmp) == false) {
       			std::cout << "Error" << std::endl;
        		return 1;
			}
		if (tmp.empty())
		  	continue;
    	vec.push_back(static_cast<int>(strtod(tmp.c_str(), NULL)));
    	}
	}

	PmergeMe merge(vec);
	std::cout << "Before: ";
	printVector(vec);
	vec.clear();

	merge.vectorSort();
	merge.dequeSort();

	return 0;
}
