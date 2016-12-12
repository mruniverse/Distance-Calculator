#include <iostream>
#include <fstream>
#include <stdio.h>
#include "library.hpp"

using namespace std;

int main(){
    string title;
    string line;
    int c = 0;

    cin >> title;

    cout << "Type the archive's name(with the extention): ";

    fstream archive;
    archive.open(title.c_str(), ios::in);

    while(archive.good()){
        getline(archive, line);
        c++;
        // cout << line << endl;
    }
    cout << endl;
    int code[c];


    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================
    archive.clear();
    archive.seekg(0, ios::beg);
    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================

    c = 0;
    while(archive.good()){
        archive >> code[c];
        c++;
    }

    for(int i = 0; i < c; i++){
        for(int j = i + 1; j < c - 1; j++){

            printf("%s;%d;%s;%d; %.3f KM\n"
            , postal(code[i]).c_str(), code[i]
            , postal(code[j]).c_str(), code[j]
            , distance(code[i], code[j]));
        }
    }

    archive.close();

    return 0;
}
