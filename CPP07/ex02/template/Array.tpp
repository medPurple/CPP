template<typename T>
Array<T>::Array() : _array(nullptr), _size(0) {
    if (msg_const == true) {
        std::cout << Array_DC << std::endl;
    }
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    if (msg_const == true){
        std::cout << Array_PC << std::endl;
    }
}

template<typename T>
Array<T>::Array(const Array& rhs) : _array(nullptr), _size(0) {
    *this = rhs;
    if (msg_const == true){
        std::cout << Array_CC << std::endl;
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
    if (this != &rhs) {
        delete[] this->_array;
        this->_size = rhs._size;
        this->_array = new T[this->_size];
        for (int i = 0; i < rhs._size; i++)
            this->_array[i] = rhs._array[i];
    }
    if (msg_const == true){
        std::cout << Array_AO << std::endl;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](const int index) {
    if (!this->_array || index < 0 || index >= this->_size)
        throw OutofRangeException();
    return this->_array[index];
}

template<typename T>
Array<T>::~Array() {
    delete[] this->_array;
    if (msg_const == true){
        std::cout << Array_DD << std::endl;
    }
}

template<typename T>
T Array<T>::size() const {
    return this->_size;
}

template<typename T>
class Array<T>::OutofRangeException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "\x1b[31m \x1b[3m Exception : Index is out of range. \x1b[0m";
    }
};
