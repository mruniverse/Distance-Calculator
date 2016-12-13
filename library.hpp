#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <iomanip>

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


//WRITE DISTANCES ON THE ARCHIVE================================================
void write(int code1, int code2){
    fstream archive;
    archive.open("distances.csv", ios::app | ios::out);

    archive << postal(code1) << ";" << code1 << ";";
    archive << postal(code2) << ";" << code2 << "; ";
    archive << fixed << setprecision(3) << distance(code1, code2) << " KM\n";

    archive.close();
}
//WRITE DISTANCES ON THE ARCHIVE================================================


void functionality1(void){
    int postal1,postal2; //Entry postal code

    cout << "Inform the Source Code: \n";
    cin >> postal1;
    cout << "Inform the Destination Code: \n";
    cin >> postal2;

    printf("%s -> %s : %f KM\n",postal(postal1).c_str(), postal(postal2).c_str(), distance(postal1, postal2));

}

void functionality2(void){
    string title;
    string line;
    int c = 0;

    cout << "Type the archive's name(with the extention): ";
    cin >> title;

    fstream archive2;
    archive2.open(title.c_str(), (ios::trunc));

    while(archive2.good()){
        getline(archive2, line);
        c++;
    }
    cout << endl;
    int code[c];


    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================
    archive2.clear();
    archive2.seekg(0, ios::beg);
    //SETTING THE ARCHIVE BACK TO THE BEGINNING=================================

    c = 0;
    while(archive2.good()){
        archive2 >> code[c];
        c++;
    }

    for(int i = 0; i < c; i++){
        for(int j = i + 1; j < c - 1; j++){

            printf("%s;%d;%s;%d; %.3f KM\n"
            , postal(code[i]).c_str(), code[i]
            , postal(code[j]).c_str(), code[j]
            , distance(code[i], code[j]));

            write(code[i], code[j]);
        }
    }

    cout << "\nThe Distances was saved with success " << endl;

    archive2.close();
}
