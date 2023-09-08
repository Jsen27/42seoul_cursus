#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string filename;
	std::string temp;
	std::ifstream ifn;
	std::ofstream ofn;

	if (argc != 4){
		std::cout << "Usage : filename , string 1 , string 2" << std::endl;
		return 1;
	}
	if (std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0 || std::strlen(argv[3]) == 0){
		std::cout << "Your string is empty !" << std::endl;
		return 1;
	}
	ifn.open(argv[1]);
	if (ifn.fail()){
		std::cout << "file open error !" << std::endl;
		return 1;
	}
	filename = argv[1];
	filename.append(".replace");
	ofn.open(filename);
	if(ofn.fail()){
		std::cout << "file open error !" << std::endl;
		return 1;
	}
	while(1){
		std::getline(ifn, temp);
		size_t pos = 0;
		while (1){
			pos = temp.find(argv[2], pos);
			if (pos == std::string::npos)
				break;
			temp.erase(pos, std::strlen(argv[2]));
			temp.insert(pos, argv[3]);
			pos += std::strlen(argv[2]);
		}
		ofn << temp;
		if (ifn.eof())
			break;
		ofn <<'\n';
	}
	ifn.close();
	ofn.close();
	return 0;
}