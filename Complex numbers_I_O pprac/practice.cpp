//
//  practice.cpp
//  lab2_practice
//
//  Created by Brandon Johns on 2/24/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include "practice.hpp"
using namespace std;
#include <iostream>


#include <string>

ComplexNumber:: ComplexNumber()
{
    real=0;
    imag=0;
}
ComplexNumber:: ComplexNumber(double r, double i)
{
    real=r;
    imag=i;
    
}

ComplexNumber ComplexNumber:: operator +(ComplexNumber& add) const
{
    ComplexNumber num;
    num.real=real +add.real;
    num. imag=imag+ add.imag;
    
    return num;
}
ComplexNumber ComplexNumber:: operator -(ComplexNumber& sub) const
{
    ComplexNumber num;
    
    num.real=real-sub.real;
    num.imag=imag-sub.imag;
    
    return num;
    
}
ComplexNumber ComplexNumber:: operator *(ComplexNumber& mul) const
{
    ComplexNumber num;
    num.real = real*mul.real - imag*mul.imag;
    num.imag = imag*mul.real + real*mul.imag;
    return num;
}
ComplexNumber ComplexNumber:: operator / (ComplexNumber& div)const
{
    ComplexNumber num;
    double denom = div.real*div.real + div.imag*div.imag;
    num.real = (real*div.real + imag*div.imag)/denom;
    num.imag = (imag*div.real - real*div.imag)/denom;
    return num;
}

void readNumber(istream& in, double& d, bool& isImaginary)
{
    double s=1.0;
    char p;
    d=0.0;
    isImaginary=false;
    in>> skipws >>ws; ///////////skipping white spaces
    p=(char)in.peek(); //checking for starting sign
    
    if(p== '-')
    {
        s=-1.0; /// makes s a negative -1
        in.ignore();/// removes sign
    }
    else if(p=='+')
    {
        in.ignore(); /// ignores sign
    }
    else if(p==')')
    {
        throw "incorrexct format. needs a number";
    }
    in>> skipws>> ws; /// removes white spaces
    p= (char) in.peek(); // cehcks for +i or -1
    
    if (p=='i')
    {
        isImaginary=true;
        d=d>0.0? 1.0: -1.0;
        in.ignore(); //consumes i
        return;// stop after the i
    }
    
    in>>d;/// this is the real or imag
    d*=s;// apply the sign
    in>>skipws>>ws;/// consume any whitespace
    
    p=(char) in.peek();// check imginary number
    if(p=='i')
    {
        isImaginary=true;
        in.ignore();
    }
}



istream& operator >> (istream&in, ComplexNumber& c)
{
    char t;
    double d;
    bool isImaginary;
    
    c.real=0.0;
    c.imag=0.0;
    
    in>> skipws>>t; /// read the input parentheses
    
    if(t!='(')
    {
        throw "format problem complex numbers do not start with a partenthesis ";
    }
    
    readNumber(in, d, isImaginary);
    
    if(isImaginary)
    {
        c.imag=d;
        in>> skipws>> ws;
        t=in.peek();
        if(t!=')')
        {
            readNumber(in, d, isImaginary);
            if(isImaginary)
            {
                throw "already read the imaginary part";
            }
            c.imag=d;
        }
    }
    else
    {
        c.real=d;
        in>> skipws>>ws;
        t=in.peek();
        if(t!=')')
        {
            readNumber(in, d, isImaginary);
            if(!isImaginary)
            {
                throw "already read real part.";
            }
            c.imag=d;
        }
    }
    in>>skipws>>t;
    if(t!=')')
    {
        throw"number does not end with parenthesis";
    }
    
    return in;
}
ostream& operator <<(ostream & out, ComplexNumber& c)
{
    out<<'(';
    if(c.real!=0)
    {
        out<<c.real;
    }
    if(c.imag!=0)
    {
        out<< showpos<< c.imag<< 'i';
    }
    
    out<< '(';
    
    return out;
    
}
