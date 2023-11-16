#pragma once

#include <iostream>
#include <string>

template <typename T>
void	iter(T *tab, size_t len, void (*f)(T&)){
	for (size_t i = 0; i < len; i++)
		f(tab[i]);
	return;
}

template <typename T>
void	iter(const T *tab, const size_t len, void (*f)(const T&)){
	for (size_t i = 0; i < len; i++)
		f(tab[i]);
	return;
}