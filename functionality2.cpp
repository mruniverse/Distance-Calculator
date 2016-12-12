#include <iostream>
#include "library.hpp"

using namespace std;

int main(){
    string title;
    string line;
    int c = 0;

    cout << "Type the archive's name(with the extention): ";
    cin >> title;

    fstream archive;
    fstream distance;
    archive.open(title, ios::in);
    distance.open("distances.csv", ios::out | ios::app);

    while(archive.good()){
        c++;
    }
    int postal[c];

    int i = 0;
    while(archive.good()){
        getline(archive,postal[i]);
        i++;
        // cout << line << endl;
        // cout << c << endl;
    }

    for(int i = 0; i < c; i++){
        for(int j = i++; j < c; j++){
            cout << postal[i] << postal[j] << endl;
        }
    }


    return 0;
}
