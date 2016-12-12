#include <iostream>
#include "library.hpp"

using namespace std;

int main(){
    int postal1,postal2; //Entry postal code

    cout << "Inform the Source Code: \n";
    // cin >> postal1;
    cout << "Inform the Destination Code: \n";
    // cin >> postal2;

    postal1 = 19600000;
    postal2 = 86360000;

    printf("%s -> %s : %f KM\n",postal(postal1).c_str(), postal(postal2).c_str(), distance(postal1, postal2));

    return 0;
}
