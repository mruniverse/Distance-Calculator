#include <iostream>
#include "library.hpp"

using namespace std;

int main(){
    int postal1,postal2; //Entry postal code

    cout << "Inform the Source Code: ";
    cin >> postal1;
    cout << "Inform the Destination Code: ";
    cin >> postal2;

    // printf("%s -> %s : %f KM\n",postal(postal1).c_str(), postal(postal2).c_str(), distance(postal1, postal2));

    cout << distance(postal1, postal2) << endl;

    return 0;
}
