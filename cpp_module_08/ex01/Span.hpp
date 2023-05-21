#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <iostream>
#include <vector>

class Span
{
private:
	size_t size_;
	std::vector<int> vec_;
public:
	Span();
	Span(const unsigned int num);
	Span(const Span& ref);
	Span& operator= (const Span& ref);
	~Span();

	void addNumber(const int num);
	size_t longestSpan();
	size_t shortestSpan();

	int getNumber()const;
};

#endif
