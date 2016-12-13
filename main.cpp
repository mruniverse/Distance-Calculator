#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include "library.hpp"

using namespace std;

int main(){
    int choice;

    cout << "What do you wanna do ?" << endl;
    cout << "[1] - Individual Calculation" << endl;
    cout << "[2] - Multiple Calculation" << endl;
    cout << ": ";

    cin >> choice;

    switch(choice){
        case 1:
            functionality1();
            break;
        case 2:
            functionality2();
            break;
    }


    return 0;
}
#endif
