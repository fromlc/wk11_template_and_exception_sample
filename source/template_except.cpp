//------------------------------------------------------------------------------
// max_template.cpp
//
// Demos:
//  - a template function from 
// https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
//  - handling a divide by zero exception
// https://stackoverflow.com/questions/6121623/catching-exception-divide-by-zero
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int DIVIDE_BY_ZERO = -99;

//------------------------------------------------------------------------------
// template function tMax
//------------------------------------------------------------------------------
template <typename T>
inline T const& tMax(T const& a, T const& b) {
    return a < b ? b : a;
}

#include <stdexcept>

//------------------------------------------------------------------------------
// Integer division, catching divide by zero.
//------------------------------------------------------------------------------
inline int intDivEx(int numerator, int denominator) {
    if (denominator == 0)
        throw std::overflow_error("Divide by zero exception");

    return numerator / denominator;
}

//------------------------------------------------------------------------------
// entry point 
//------------------------------------------------------------------------------
int main() {

    // template function demo
    int i = 39;
    int j = 20;
    cout << "tMax(i, j): " << tMax(i, j) << '\n';

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "tMax(f1, f2): " << tMax(f1, f2) << '\n';

    string s1 = "Hello";
    string s2 = "World";
    cout << "tMax(s1, s2): " << tMax(s1, s2) << '\n';

    // divide by zero demo
    int divResult;
    try {
        divResult = intDivEx(100, 0);
    }
    catch (std::overflow_error& e) {
        cout << '\n' << e.what() << '\n';
        exit(DIVIDE_BY_ZERO);
    }

    // execution resumes after catch block,
    // unless we exit() from the catch block
    cout << "After catch block\n";

    return 0;
}