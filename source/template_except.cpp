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
#include <stdexcept>
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
// throws an exception of type int
//------------------------------------------------------------------------------
inline void throwInt() {
    throw 20;
}

//------------------------------------------------------------------------------
// causes an exception of type char to be thrown
//------------------------------------------------------------------------------
void throwChar5() { 
    throw '?';
}

void throwChar4() { throwChar5(); }

void throwChar3() { throwChar4(); }

void throwChar2() { throwChar3(); }

void throwChar1() { throwChar2(); }

void throwChar() { throwChar1(); }

//------------------------------------------------------------------------------
// Integer division, catching divide by zero.
//------------------------------------------------------------------------------
inline int intDivEx(int numerator, int denominator) {
    if (denominator == 0)
        throw std::overflow_error("Divide by zero!!!!");

    return numerator / denominator;
}

//------------------------------------------------------------------------------
// template function tMax
//------------------------------------------------------------------------------
template <typename T>
T tMax(T a, T b) {
    return a < b ? b : a;
}

//------------------------------------------------------------------------------
// entry point 
//------------------------------------------------------------------------------
int main() {

    cout << "Exception demo\n\n";

    // store results of try block operations
    int divResult;
    int intValueOfStr = -99;

    try {
        //throwChar();
        //throwInt();
        intValueOfStr = std::stoi("xx");    // "0x123"
        divResult = intDivEx(100, 0);
    }
    //catch (std::invalid_argument& e) {
    //    cout << '\n' << e.what() << '\n';
    //    // ... handle error
    //}
    catch (std::out_of_range& e) {
        cout << '\n' << e.what() << '\n';
        // ... handle error
        // errorHandler(e);
    }
    //catch (std::overflow_error& e) {
    //    cout << '\n' << e.what() << '\n';
    //  // ... handle error
    //  // errorHandler(e);
    //}
    //catch (std::exception& e) {
    //    cout << '\n' << e.what() << '\n';
    //    // ... handle error
    //    // errorHandler(e);
    //}
    catch (int e) {
        cout << "This int was thrown: " << e << '\n';
        // ... handle error
        // errorHandler(e);
    }
    catch (char e) {
        cout << "This char was thrown: " << e << '\n';
        // ... handle error
        // errorHandler(e);
    }
    catch (...) {
        cout << "Unknown error occurred\n";
        // ... handle error
        // errorHandler(e);
    }

    // execution resumes after catch block,
    // unless we exit() from the catch block
    cout << "After catch block\n\n";
    cout << "Result of divide: " << intDivEx << '\n';
    cout << "Result of std::stoi(): " << intValueOfStr << '\n';

    cout << "Template function tMax<>() demo\n\n";

    // template function demo
    int i = 39;
    int j = 20;
    cout << "Max of two ints: tMax(i, j): " << tMax(i, j) << '\n';

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max of two doubles: tMax(f1, f2): " << tMax(f1, f2) << '\n';

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max of two strings: tMax(s1, s2): " << tMax(s1, s2) << '\n';

    return 0;
}