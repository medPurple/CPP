#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <deque>


template <typename T>
void mergeInsertSort(std::vector<T>& data) {
    /*create 2 vector
     fill with half vector data
     
     insertion sort
     merge sort
    */

    std::sort(data.begin(), data.end());
}

template <typename T>
void mergeInsertSort(std::deque<T>& data) {
    /*create 2 vector
     fill with half vector data
     
     insertion sort
     merge sort
    */

    std::sort(data.begin(), data.end());
}

template<typename T>
void    print(std::vector<T> &tab){
    std::cout << " Type : Vector" << std::endl;
	std::vector<T> tmp = tab;
	while (!tmp.empty()) {
		std::cout << tmp.back() << " ";
		tmp.pop_back();
	}
	std::cout << std::endl;
	return;
}

template<typename T>
void    print(std::deque<T> &tab){
    std::cout << " Type : Deque" << std::endl;
	std::deque<T> tmp = tab;
	while (!tmp.empty()) {
		std::cout << tmp.back() << " ";
		tmp.pop_back();
	}
	std::cout << std::endl;
	return;
}