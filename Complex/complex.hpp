//
//  complex.hpp
//  lab8
//
//  Created by Brandon Johns on 4/25/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//

#ifndef complex_hpp
#define complex_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
class complex
{
public:
    complex (double r = 0, double i = 0): re (r), im (i) { }
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;
    friend double real (const complex&) ;
    friend double imag (const complex&) ;
    friend complex operator + (const complex&, const
                               complex&);
    friend complex operator - (const complex&,
                               const complex&);
    friend complex operator * (const complex&,
                               const complex&);
    friend complex operator / (const complex&,
                               const complex&);
    friend bool operator == (const complex&,
                             const complex&);
    friend bool operator != (const complex&,
                             const complex&);
    friend complex polar (double, double);
    friend istream& operator>> (istream&, complex&);
    friend ostream& operator<< (ostream&, const complex&);
};
double norm (const complex& x);



#endif /* complex_hpp */
