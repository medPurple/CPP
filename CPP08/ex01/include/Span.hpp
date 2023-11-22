#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    public			:
                Span(unsigned int n);
                Span(const Span& rhs);
                Span &operator=(const Span& rhs);
                ~Span();

                void            addNumber(int n);
                unsigned long   shortestSpan();
                unsigned long   longestSpan();
                void            AddVector();
                std::vector<int> GetContainer() const;

                class SizeExceedException : public std::exception {
                    const char * what() const throw() ;};

                class ImpossibleCompareException : public std::exception {
                    const char * what() const throw() ;};

    protected   	:

    private     	:
                Span();
                void _display_constructor(std::string msg){
                    std::cout << "\x1b[33m \x1b[3m" << msg << "\x1b[0m" << std::endl;
                }

                unsigned int _N;
                std::vector<int> _container;
};

static bool msg_const = false;

//std::ostream& operator<<(std::ostream& os, const Span& span);

#define Span_DC "[Default] Constructor called for SPAN CLASS"
#define Span_PC "[Parametric] Constructor called for SPAN CLASS"
#define Span_CC "[Copy] Constructor called for SPAN CLASS"
#define Span_AO "[Attribution] Operator called for SPAN CLASS"
#define Span_DD "[Default] Destructor called for SPAN CLASS"