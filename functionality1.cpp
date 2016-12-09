#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "library.hpp"

using namespace std;

float distance(int,int);


int main(){
    int postal1,postal2; //Entry postal code
    string aux;

    cout << "Inform the Source Code: ";
    cin >> postal1;
    cout << "Inform the Destination Code: ";
    cin >> postal2;

    cout << postal(postal1) << " --> ";
    cout << postal(postal2) << endl;

    distance(postal1, postal2);

    return 0;
}

float distance(int pcode1, int pcode2){
    string city;
    string line;
    string adress1,adress2;
    float R = 6372.795477598;

    fstream archive;
    archive.open("municipios_br.csv", ios::in);
    city = postal(pcode1);

    while(archive.good()){
        getline(archive, line);
        vector<string> tokens = split(line, ';');
        address1 = tokens[3] + tokens[4];

        if(address1 == city){
            cout << address1 << endl;
            break;
        }

    }
    archive.clear();
    archive.seekg(0, ios::beg);
    city = postal(pcode2);

    while(archive.good()){
        getline(archive, line);
        vector<string> tokens = split(line, ';');
        address2 = tokens[3] + tokens[4];

        if(address2 == city){
            cout << address2 << endl;
            break;
        }

    }

    int A = sin()


    archive.close();
    return 0;
}
