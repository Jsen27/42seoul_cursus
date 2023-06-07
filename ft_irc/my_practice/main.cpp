#include "Server.hpp"


int main(int argc, char** argv)
{
	if (argc != 3)
		return -1;
	
	Server server_(argv[1], argv[2]);


	return 0;
}