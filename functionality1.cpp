#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "library.hpp"

using namespace std;

string postal(int);

int main(){
    int postal1,postal2; //Entry postal code
    string aux;

    cout << "Inform the Source Code: ";
    cin >> postal1;
    cout << "Inform the Destination Code: ";
    cin >> postal2;

    cout << postal(postal1) << endl;
    cout << postal(postal2) << endl;

}
