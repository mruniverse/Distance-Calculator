#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include "functionality1.hpp"
#include "functionality2.hpp"

using namespace std;

void functionality1(void);
void functionality2(void);

int main(){
    int choice;

    cout << "What do you wanna do ?" << endl;
    cout << "[1] - Individual Calculation" << endl;
    cout << "[2] - Multiple Calculation" << endl;
    cout << ": ";

    cin >> choice;

    // functionality1(void);

    return 0;
}
#endif
