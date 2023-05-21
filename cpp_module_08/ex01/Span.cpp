#include "Span.hpp"

Span::Span(){}

Span::Span(const unsigned int num) : size_(num){}

Span::Span(const Span& ref) : size_(ref.size_), vec_(ref.vec_){}

Span& Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		size_ = ref.size_;
		vec_ = ref.vec_;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(const int num)
{
	if (size_ == vec_.size())
		throw std::runtime_error("The maximum number of elements has already been saved.");
	vec_.push_back(num);
}

size_t Span::longestSpan()
{
	if (size_ < 2)
		throw std::runtime_error("2 or more numbers must be stored");
	
	std::vector<int>tmp(vec_);
	std::sort(tmp.begin(), tmp.end());
	return static_cast<size_t>(tmp.back() - *tmp.begin());
}

size_t Span::shortestSpan()
{
	if (size_ < 2)
		throw std::runtime_error("2 or more numbers must be stored");
	
	long result = LONG_MAX;
	int prev;
	std::vector<int>tmp(vec_);

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++){
		if (iter == tmp.begin())
			prev = *iter;
		else if (result > *iter - prev)
			result = *iter - prev;
		prev = *iter;
	}
	return static_cast<size_t>(result);
}
