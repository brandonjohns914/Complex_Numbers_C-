//
//  Polynomial-partial.cpp
//  lab8
//
//  Created by Brandon Johns on 4/25/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//

#include "Polynomial-partial.hpp"
#include <iostream>
#include <cmath>


Polynomial::Polynomial()
{
    degree = 10;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = 0;
    }
}

Polynomial::Polynomial(int degr)
{
    degree = degr;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &poly)
{
    degree = poly.get_degree();
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = poly.get_coeff(i);
    }
}

Polynomial::Polynomial(double cf[], int deg)
{
    degree = deg;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = cf[i];
    }
}

Polynomial::~Polynomial()
{
    delete [] coeff;
}

int Polynomial::get_degree() const
{
    return degree;
}

double Polynomial::get_coeff(int deg) const
{
    if (degree < deg)
    {
        return 0;
        // The input degree is larger than the polynomial degree
    }
    return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
    if (degree < degr)
    {
        cout << "Degree exceeded." << endl;
        return;
    }
    coeff[degr] = val;
}

// Evaluate the polynomial
double Polynomial::evaluate(double val)
{
    double power = 1,
    result = 0;
    
    for (int i = 0; i <= degree; i++)
    {
        result += coeff[i] * power;
        power *= val;
    }
    
    return result;
}

// Assignment operator
void Polynomial::operator =(const Polynomial &poly)
{
    if (this == &poly)
    {
        // Copy to itself. Nothing to be done.
        return;
    }
    
    for (int i=0; i < 10; i++)
        this->coeff[i] = poly.coeff[i];
}

// Overloaded operator +
Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
    int l = pola.get_degree();
    int r = polb.get_degree();
    int degree;
    double sum;
    
    if ( l > r )
        degree = l;
    else
        degree = r;
    
    Polynomial resPoly;
    
    for ( int i=degree; i >= 0; i-- )
    {
        sum = pola.get_coeff( i ) + polb.get_coeff( i );
        if ( sum != 0.0 )               // Don't need to set coefficients that are 0.0
            resPoly.set_coeff( i, sum );   // Also makes sure that degree is correctly set
    }
    
    return resPoly;
    
    
}

// Overloaded operator -
Polynomial operator-(const Polynomial &pola, const Polynomial &polb)
{
    int l = pola.get_degree();
    int r = polb.get_degree();
    int degree;
    double sum;
    
    if ( l > r )
        degree = l;
    else
        degree = r;
    
    Polynomial resPoly;
    
    for ( int i=degree; i >= 0; i-- )
    {
        sum = pola.get_coeff( i ) - polb.get_coeff( i );
        if ( sum != 0.0 )               // Don't need to set coefficients that are 0.0
            resPoly.set_coeff( i, sum );   // Also makes sure that degree is correctly set
    }
    
    return resPoly;
    
    
}

// Overloaded << operator
ostream& operator << (ostream& ost, const Polynomial &pol)
{
    if ( pol.get_degree( ) == -1 )
    {
        cout << 0;
        return ost;
    }
    ost << pol.get_coeff( pol.get_degree( ) ) << "x^" << pol.get_degree( );
    for (int i = pol.get_degree( )-1; i >= 0; i--)
    {
        ost << " + ";
        if ( pol.get_coeff( i ) < 0.0 )
            ost << '(' << pol.get_coeff( i ) << ')';
        else
            ost << pol.get_coeff( i );
        ost << "x^" << i;
    }
    
    return ost;
}


Polynomial operator*(const Polynomial &polya, const Polynomial &polyb)
{
    
    Polynomial product;
    
    product.degree = polya.degree + polyb.degree;
    
    delete [] product.coeff;
    
    product.coeff = new double[product.degree];
    
    for (int i = 0; i < product.degree; i++) {
        
        product.coeff[i] = 0;
        
    }
    
    for (int i = 0; i < polya.degree; i++) {
        
        for (int j = 0; j < polyb.degree; j++) {
            
            product.coeff[i + j] += polya.coeff[i] * polyb.coeff[j];
            
        }
        
    }
    
    return product;
    
}
