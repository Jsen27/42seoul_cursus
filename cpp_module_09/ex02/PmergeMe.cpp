#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& vec)
: _vec(vec.begin(), vec.end()), _deq(vec.begin(), vec.end())
{}

PmergeMe::PmergeMe(const PmergeMe& ref)
: _vec(ref._vec), _deq(ref._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe&ref)
{
	if (this != &ref){
		this->_vec.assign(ref._vec.begin(), ref._vec.end());
		this->_deq.assign(ref._deq.begin(), ref._deq.end());
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::mergeSortVector(int left, int mid, int right)
{
	int l = left;
	int r = mid + 1;
	int k = left;
	std::vector<int> tmp(right - left + 1);

	while (l <= mid && r <= right)
		tmp[k++] = _vec[l] <= _vec[r] ? _vec[l++] : _vec[r++];

	if (l > mid){
		for (int i = r; i <= right; i++)
			tmp[k++] = _vec[i];
	} else{
		for (int i = l; i <= mid; i++)
			tmp[k++] = _vec[i];
	}

	for(int i = left; i <= right; i++)
		_vec[i] = tmp[i];
}

void PmergeMe::insertSortVector(int left, int right)
{
	for (int i = left + 1; i <= right; i++){
		int key = _vec[i];
		int j = i - 1;
		for (; j >= left && _vec[j] > key; j--){
			_vec[j + 1] = _vec[j];
		}
		_vec[j + 1] = key;
	}
}

void PmergeMe::mergeInsertSortVector(int left, int right, int pivot)
{
	if (right - left + 1 <= pivot)
		insertSortVector(left, right);
	else if (left < right){
		int tmp = left + (right - left) / 2;
		mergeInsertSortVector(left, tmp, pivot);
		mergeInsertSortVector(tmp + 1, right, pivot);
		mergeSortVector(left, tmp, right);
	}
}

void PmergeMe::vectorSort()
{
	clock_t startTime = clock();

	mergeInsertSortVector(0, _vec.size() - 1, 5);

	clock_t endTime = clock();
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << _vec.size() << " elements with std::vector :" << endTime - startTime << "ms" << std::endl;
}
