//
//  main.cpp
//  lab8
//
//  Created by Brandon Johns on 4/25/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Polynomial-partial.hpp"
#include "Polynomial-partial.cpp"
#include "complex.cpp"
#include "complex.hpp"




using namespace std;

int main()
{
    ///1
    
    Polynomial p1;
    
    Polynomial p2(3);
    
    double a[] = {1, -2, 3, 4};
    
    double b[] = {50, 0, 1};
    
    Polynomial p3(a, 4);
    
    Polynomial p4(b, 3);
    
    cout << "p1: " << p1 << endl;
    
    cout << "p2: " << p2 << endl;
    
    cout << "p3: " << p3 << endl;
    
    cout << "p4: " << p4 << endl;
    
    cout << "------------------------------" << endl;
    
    Polynomial p5 = p1 + p2 + p3;
    
    cout << "p5 = p1 + p2 + p3: \n" << "p5: " << p5 << endl;
    
    Polynomial p6 = p1 - p2;
    
    cout << "p1 - p2\n" << p6 << endl;
    
    p6 = p2 - p2;
    
    cout << "p2 - p2\n" << p6 << endl;
    
    p6 = p2 - p1;
    
    cout << "p2 - p1\n" << p6 << endl;
    
    cout << "p4 - p3: " << (p4 - p3) << endl;
    
    cout << "p1 * p3: " << (p1 * p3) << endl;
    
    cout << "p2 * p3: " << (p2 * p3) << endl;
    
    cout << "p4 * p3: " << (p4 * p3) << endl;
    
    //2
    
    complex x, y(3), z(-3.2, 2.1);
    cout <<"x = " << x << " y = " << y
    << " z = " << z << endl << endl;
    x = complex(3, -4);
    cout << "testing members and support functions as "
    << " well as output operator:\n"
    << "complex number x = " << x << endl
    << "real part: " << x.real() << endl
    << "real part from friend real(x): "
    << real(x) << endl
    << "imaginary part: " << x.imag() << endl
    << "imaginary part from friend imag(x) : "
    << imag(x) << endl
    << "norm: " << norm(x) << endl << endl;
    cout << "test complex arithmetic and output"
    << " routines: \n\n";
    y = complex (1, -1);
    cout << "x = " << x << " y = " << y
    << " z = " << z << endl << endl;
    z = x + y;
    cout << "z = x + y = " << z << endl;
    z = x * y;
    cout << "z = x * y = " << z << endl;
    z = x - y;
    cout << "z = x - y = " << z << endl;
    z = x / y;
    cout << "z = x / y = " << z << endl << endl;
    //test of automatic conversion double -> complex by the
    //constructor.
    double d(2.0);
    cout << "d: " << d << " x: " << x <<endl;
    cout << "x+d: " ;
    z = x + d;
    cout << z << endl;
    z = x - d;
    cout << "x-d: " ;
    cout << z << endl;
    z = x * d;
    cout << "x*d: ";
    cout << z << endl;
    z = x / d;
    cout << "x/d: " ;
    cout << z << endl;
    z = d + x;
    cout << "d+x: " ;
    cout << z << endl;
    z = d - x;
    cout << "d-x: " ;
    cout << z << endl;
    z = d * x;
    cout << "d*x: " ;;
    cout << z << endl;
    z = d / x;
    cout << "d/x: " ;;
    cout << z << endl;
    //test whether double/complex and complex/complex
    //give same result:
    complex two(2,0);
    cout << "two/x: ";
    cout << two/x << endl;
    cout << "\nGetting data from standard input: \n";
    cin >> x >> y;
    cout << "data read is: x = " << x
    << " y = " << y << endl << endl;
    
}
