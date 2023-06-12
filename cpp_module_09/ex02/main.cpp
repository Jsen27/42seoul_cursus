#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2){
		std::cout << "Usage: ./PmergeMe \"number\"" << std::endl;
		return -1;
	}

	std::vector<int> vec;
	
	for (int i = 1; i <= argc; i++){
		std::stringstream ss;
		std::string tmp;
		ss << argv[i];
		while (std::getline(ss, tmp, ' ')){
			
		}
	}

	return 0;
}