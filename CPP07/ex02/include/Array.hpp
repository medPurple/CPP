// Array.hpp

#pragma once

#include <string>
#include <iostream>

template<typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& rhs);
    Array& operator=(const Array& rhs);
    T& operator[](const int index);
    ~Array();
    T size() const;

private:
    T* _array;
    int _size;

    class OutofRangeException;
};


// Activation constructor message
static bool msg_const = false;
#define Array_DC "[Default] Constructor called"
#define Array_PC "[Parametric] Constructor called"
#define Array_CC "[Copy] Constructor called"
#define Array_AO "[Attribution] Operator called"
#define Array_DD "[Default] Destructor called"


#include "../template/Array.tpp"  // Inclure les templates ici pour que le compilateur puisse les instancier
