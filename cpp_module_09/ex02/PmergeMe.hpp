#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <iomanip>

class PmergeMe{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
public:
	PmergeMe(const std::vector<int>& vec);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator=(const PmergeMe& ref);
	~PmergeMe();

	void mergeSortVector(int left, int mid, int right);
	void insertSortVector(int left, int right);
	void mergeInsertSortVector(int left, int right, int pivot);
	void vectorSort();

	void mergeSortDeque(int left, int mid, int right);
	void insertSortDeque(int left, int right);
	void mergeInsertSortDeque(int left, int right, int pivot);
	void dequeSort();
};

#endif
