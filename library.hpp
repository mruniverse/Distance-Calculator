#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <math.h>

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


//FIND THE CITY THROUGH THE POSTAL CODE=========================================
string postal(int pcode){
    int ref1,ref2,ref3; //Referencials of ";"
    int code1,code2; //Exit postal codes
    string aux;
    string aux1,aux2;
    string line;
    string Rstring;

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
            Rstring = city + "-" + initials;
            break;
        }
    }
    archive.clear();
    archive.seekg(0, ios::beg);
    archive.close();

    return Rstring;
}
//FIND THE CITY THROUGH THE POSTAL CODE=========================================



//CALCULATE THE DISTANCE========================================================
float distance(int pcode1, int pcode2){
    string city;
    string line;
    string address1,address2;
    float R = 6372.795477598;
    float PI = 3.1415926536;
    float lat1,long1,lat2,long2;
    float distance;
    
    fstream archive;
    archive.open("municipios_br.csv", ios::in);
    city = postal(pcode1);

    while(archive.good()){
        getline(archive, line);
        vector<string> tokens = split(line, ';');
        address1 = tokens[3] + "-" + tokens[4];
        lat1 = stof(tokens[1]);
        long1 = stof(tokens[2]);

        if(address1 == city){
            break;
        }
    }

    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================
    archive.clear();
    archive.seekg(0, ios::beg);
    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================

    city = postal(pcode2);

    while(archive.good()){
        getline(archive, line);
        vector<string> tokens = split(line, ';');
        address2 = tokens[3] + "-" + tokens[4];
        lat2 = stof(tokens[1]);
        long2 = stof(tokens[2]);

        if(address2 == city){
            break;
        }
    }


    //CONVERSION: DEGREES TO RADIANS============================================
    lat1 = lat1 * PI/180;
    long2 = long2 * PI/180;
    long1 = long1 * PI/180;
    lat2 = lat2 * PI/180;
    //CONVERSION: DEGREES TO RADIANS============================================



    //CALCULATING THE EARTH'S CURVATURE=========================================
    float A = sin(lat1) * sin(lat2);
    float B = cos(lat1) * cos(lat2);
    float C = cos(long1 - long2);
    //CALCULATING THE EARTH'S CURVATURE=========================================

    distance = R * acos(A + B * C);

    archive.close();
    return distance;
}
//CALCULATE THE DISTANCE========================================================
