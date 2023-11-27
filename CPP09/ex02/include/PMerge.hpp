#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <deque>
#include <cstdlib>
#include <climits>


void start_sort(std::vector<int>vector, std::deque<int>deque);


class ErrorException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

template<typename T>
void    print(std::vector<T> &tab){
    std::cout << " Type : Vector\t| " ;
    std::vector<T> tmp = tab;
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " | ";
    std::cout << std::endl;
    return;
}

template<typename T>
void    print(std::deque<T> &tab){
    std::cout << " Type : Deque\t| " ;
    std::deque<T> tmp = tab;
    for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " | ";
    std::cout << std::endl;
    return;
}

template <typename T>
void mergeInsertSort(std::vector<T>& data) {
    std::vector<int> v1(data.begin(), data.begin() + data.size() / 2);
	std::vector<int> v2(data.begin() + data.size() / 2, data.end());

	for (unsigned long i = 1; i < v1.size(); i++){
		long key = v1[i];
		long value = i - 1;
		while (value >= 0 && v1[value] > key)
		{
				v1[value + 1] = v1[value];
				value--;
		}
		v1[value + 1] = key;
	}
	for (unsigned long i = 1; i < v2.size(); i++){
		long key = v2[i];
		long value = i - 1;
		while (value >= 0 && v2[value] > key)
		{
				v2[value + 1] = v2[value];
				value--;
		}
		v2[value + 1] = key;
	}
    unsigned long i = 0, j = 0, k = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            data[k] = v1[i];
            i++;
        } else {
            data[k] = v2[j];
            j++;
        }
        k++;
    }
    while (i < v1.size()) {
        data[k] = v1[i];
        i++;
        k++;
    }
    while (j < v2.size()) {
        data[k] = v2[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeInsertSort(std::deque<T>& data) {

	std::deque<int> d1(data.begin(), data.begin() + data.size() / 2);
	std::deque<int> d2(data.begin() + data.size() / 2, data.end());
	for (unsigned long i = 1; i < d1.size(); i++){
		long key = d1[i];
		long value = i - 1;
		while (value >= 0 && d1[value] > key)
		{
				d1[value + 1] = d1[value];
				value--;
		}
		d1[value + 1] = key;
	}
	for (unsigned long i = 1; i < d2.size(); i++){
		long key = d2[i];
		long value = i - 1;
		while (value >= 0 && d2[value] > key)
		{
				d2[value + 1] = d2[value];
				value--;
		}
		d2[value + 1] = key;
	}
    unsigned long i = 0, j = 0, k = 0;
    while (i < d1.size() && j < d2.size()) {
        if (d1[i] < d2[j]) {
            data[k] = d1[i];
            i++;
        } else {
            data[k] = d2[j];
            j++;
        }
        k++;
    }
    while (i < d1.size()) {
        data[k] = d1[i];
        i++;
        k++;
    }
    while (j < d2.size()) {
        data[k] = d2[j];
        j++;
        k++;
    }
}