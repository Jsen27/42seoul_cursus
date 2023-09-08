#include "PmergeMe.hpp"

void printVector(std::vector<int>& vec);

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
	int k = 0;
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

	for(int i = left, k = 0; i <= right; i++, k++)
		_vec[i] = tmp[k];
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
		int mid = left + (right - left) / 2;
		mergeInsertSortVector(left, mid, pivot);
		mergeInsertSortVector(mid + 1, right, pivot);
		mergeSortVector(left, mid, right);
	}
}

void PmergeMe::vectorSort()
{
	clock_t startTime = clock();

	mergeInsertSortVector(0, _vec.size() - 1, 5);

	clock_t endTime = clock();

	std::cout << "After: ";
	printVector(_vec);

	std::cout << "Time to process a range of " << std::setw(4) << _vec.size() << " elements with std::vector :" << endTime - startTime << "ms" << std::endl;
}

void PmergeMe::mergeSortDeque(int left, int mid, int right)
{
	int l = left;
	int r = mid + 1;
	int k = 0;
	std::deque<int> tmp(right - left + 1);

	while (l <= mid && r <= right)
		tmp[k++] = _deq[l] <= _deq[r] ? _deq[l++] : _deq[r++];

	if (l > mid){
		for (int i = r; i <= right; i++)
			tmp[k++] = _deq[i];
	} else{
		for (int i = l; i <= mid; i++)
			tmp[k++] = _deq[i];
	}

	for(int i = left, k = 0; i <= right; i++, k++)
		_deq[i] = tmp[k];
}

void PmergeMe::insertSortDeque(int left, int right)
{
	for (int i = left + 1; i <= right; i++){
		int key = _deq[i];
		int j = i - 1;
		for (; j >= left && _deq[j] > key; j--){
			_deq[j + 1] = _deq[j];
		}
		_deq[j + 1] = key;
	}
}

void PmergeMe::mergeInsertSortDeque(int left, int right, int pivot)
{
	if (right - left + 1 <= pivot)
		insertSortDeque(left, right);
	else if (left < right){
		int mid = left + (right - left) / 2;
		mergeInsertSortDeque(left, mid, pivot);
		mergeInsertSortDeque(mid + 1, right, pivot);
		mergeSortDeque(left, mid, right);
	}
}

void PmergeMe::dequeSort()
{
	clock_t startTime = clock();

	mergeInsertSortDeque(0, _deq.size() - 1, 5);

	clock_t endTime = clock();

	std::cout << "Time to process a range of " << std::setw(4) << _deq.size() << " elements with std::deque :" << endTime - startTime << "ms" << std::endl;
}
