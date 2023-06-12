#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2){
		std::cout << "Usage ex) ./RPN \"5 5 +\"" << std::endl;
		return -1;
	}

	RPN rpn;
	rpn.start(argv[1]);


	return 0;
}
