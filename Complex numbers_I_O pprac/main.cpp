//
//  main.cpp
//  lab2_practice
//
//  Created by Brandon Johns on 2/24/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include <iostream>
#include "practice.cpp"

#include<fstream>
#include<istream>
#include<sstream>
using namespace std;

void performComplexOperation(istream &fin, ostream &fout);

void performComplexOperation(istream &fin, ostream &fout)
{
    ComplexNumber c1(0,0), c2(0,0), c3(0,0);
    char op = '\0';
    fin >> skipws >> c1; // Read first complex number
    fin >> skipws >> op; // Read operator
    if(op != '+' && op != '-' && op != '*' && op != '/'){
        throw "Incorrect format. Operator not detected.";
    }
    fin >> skipws >> c2; // Read second complex number
    if(op == '+'){
        c3 = c1 + c2;
    } else if (op == '-'){
        c3 = c1 - c2;
    } else if (op == '*'){
        c3 = c1 * c2;
    } else if (op == '/'){
        c3 = c1 / c2;
    }
    fout << c3 << endl;
    cout << "Result: " << c3 << endl;
}

int main()
{
    ifstream fin("complexInput.txt");
    ofstream fout("complexOutput.txt");
    string line;
    // Double-check files exist
    if (!fin || !fout) {
        cout << "Cannot open input or output files.\n";
        return 1;
    }
    while(!fin.eof()){
        
        getline(fin, line); // Parse one line at at time
        cout << "Line: '" << line << "'" << endl;
        stringstream ss(line); // make line into stream for processing
        
        try{
            performComplexOperation(ss, fout);
        }
        catch(const char* c){
            cout << "Error: " << c << endl;
            fout << c << endl;
        }
    }
    
    
    
    
    
    
    
    
    return 0;
}
