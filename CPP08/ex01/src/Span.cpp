#include "Span.hpp"




/*----------------- Coplien ------------- */

Span::Span() : _N(0){
    if (msg_const)
        _display_constructor(Span_DC);
}

Span::Span(unsigned int n): _N(n){
    if (msg_const)
        _display_constructor(Span_PC);
}

Span::Span(const Span& rhs){
    *this = rhs;
    if (msg_const)
        _display_constructor(Span_CC);
}

Span &Span::operator=(const Span& rhs){
    if (this != &rhs)
        *this = rhs;
    if (msg_const)
        _display_constructor(Span_AO);
    return *this;
}

Span::~Span(){
    _container.clear();
    if (msg_const)
        _display_constructor(Span_DC);
}


/*---------------- Operator ------------- */
/*std::ostream& operator<<(std::ostream& os, const Span span) {
        os << "[ ";
        for (int i = 0; i < (int)span.GetContainer().size(); i++) {
            os << span.GetContainer()[i] << " | ";
        }
        os << "]";
        return os;
    }
*/
/*---------- Getter / Setter ------------ */
std::vector<int> Span::GetContainer() const{
    return _container;
}

/*--------------- Function -------------- */

void Span::addNumber(int n){
    if (_container.size() == _N)
        throw SizeExceedException();
    _container.push_back(n);
}



unsigned long Span::shortestSpan(){
    if (_container.size() < 2)
        throw ImpossibleCompareException();
    std::sort(_container.begin(), _container.end());
    long value = _container[1] - _container[0];
    for (int i = 2; i < (int)_container.size(); i++)
        if (_container[i] - _container[i - 1] < value)
            value = _container[i] - _container[i - 1];
    return value;
}

unsigned long Span::longestSpan(){
    if (_container.size() < 2)
        throw ImpossibleCompareException();
    std::sort(_container.begin(), _container.end());
    return _container[(int)_container.size() - 1] - _container[0];
}

void Span::AddVector(){
    if (_container.size() == _N)
        throw SizeExceedException();
    srand(time(NULL));
    for (int i = (int)_container.size(); (unsigned int)i < _N; i++)
        _container.push_back(rand() % (_N * 10));
}

/*--------------- Exception ------------- */


const char * Span::SizeExceedException::what() const throw(){
    return ("\x1b[31m \x1b[3m Size exceed on vector \x1b[0m");
}

const char * Span::ImpossibleCompareException::what() const throw(){
    return ("\x1b[31m \x1b[3m Impossible to compare value \x1b[0m");

}