#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN{
private:
	std::stack<double> _rpn;

public:
	RPN();
	RPN(const RPN& ref);
	RPN& operator= (const RPN& ref);
	~RPN();

	void ssSet(std::stringstream& ss, char c);
	double calcurator(char oper);
	void start(char* argv);
};

#endif
