#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& ref) {(void) ref;}

RPN& RPN::operator=(const RPN& ref) {(void)ref; return *this;}

RPN::~RPN() {}

void RPN::ssSet(std::stringstream& ss, char c)
{
	ss.clear();
	ss.str("");
	ss << c;
}

double RPN::calcurator(char oper)
{
	double num1;
	double num2;

	num2 = _rpn.top();
	_rpn.pop();
	num1 = _rpn.top();
	_rpn.pop();

	if (oper == '+')
		return num1 + num2;
	if (oper == '-')
		return num1 - num2;
	if (oper == '*')
		return num1 * num2;
	if (oper == '/')
		return num1 / num2;
	return 0;
}

void RPN::start(char* argv)
{
	size_t len = std::strlen(argv);
	std::stringstream ss;
	std::string oper = "+-*/";
	double tmp;
	char c;
	int flag = 0;

	
	for (size_t i = 0; i < len; i++){
		if (argv[i] == ' '){
			flag = 0;
			continue;
		}
		ssSet(ss, argv[i]);
		if (ss >> tmp){
			if (tmp >= 10 || flag == 1){
				std::cout << "Error !" << std::endl;
				return;
			}
			_rpn.push(tmp);
			flag = 1;
		}
		else{
			ssSet(ss, argv[i]);
			if (ss >> c){
				if (oper.find(c) != std::string::npos){
					if (_rpn.size() >= 2 && flag == 0)
						_rpn.push(calcurator(c));
					else{
						std::cout << "Error !" << std::endl;
						return;
					}
					flag = 1;
				}
				else{
					std::cout << "Error !" << std::endl;
					return;
				}
			}
		}
	}
	if (_rpn.size() == 1)
		std::cout << _rpn.top() << std::endl;
	else
		std::cout << "Error !" << std::endl;
}
