//
//  practice.hpp
//  lab2_practice
//
//  Created by Brandon Johns on 2/24/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef practice_hpp
#define practice_hpp

#include <stdio.h>

#include <string>

using namespace std;


class ComplexNumber
{
    
private:
    double real;
    double imag;
    
    
public:
    ComplexNumber();
    ComplexNumber(double r, double i);
    
    ComplexNumber operator +(ComplexNumber& add) const;
    ComplexNumber operator -(ComplexNumber& sub) const;
    ComplexNumber operator *(ComplexNumber& mul) const;
    ComplexNumber operator / (ComplexNumber& div)const;
    
    friend istream& operator >>(istream&in, ComplexNumber& c);
    friend ostream& operator <<(ostream & out, ComplexNumber& c);
    
    
    
    
};




#endif /* practice_hpp */
