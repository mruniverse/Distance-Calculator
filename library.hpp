#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

//SPLIT=========================================================================
vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}
//SPLIT=========================================================================



//POSTAL========================================================================
string postal(int pcode){
    int ref1,ref2,ref3; //Referencials of ";"
    int code1,code2; //Exit postal codes
    string aux;
    string aux1,aux2;
    string line;

    fstream archive;
    archive.open ("cep.csv", ios::in);

    while(archive.good()){
        getline(archive, line);
        ref1 = line.find(';');
        for(int i = ref1; i < line.length(); i++){
            if(line[i] == ';'){
                ref3 = i;
            }
        }

        aux = line.substr(ref1 + 1,ref3 - ref1 - 1);
        ref2 = aux.find(';');
        aux1 = aux.substr(0,ref2);
        aux2 = aux.substr(ref2 + 1, aux.length());

        code1 = atoi(aux1.c_str());
        code2 = atoi(aux2.c_str());

        string city = line.substr(0,ref1);
        string initials = line.substr(ref3 + 1, line.length());

        if(pcode >= code1 && pcode <= code2){
            aux = (city + initials);
            break;
        }
    }
    archive.clear();
    archive.seekg(0, ios::beg);
    archive.close();

    return aux;
}
//POSTAL========================================================================
