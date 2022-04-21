/*
File:        Fraction.cpp
Author:      L Veselova
Description: Fraction class that serves as a wrapper to hide fractional calculations and 
comparisons between fractional objects. Overrides arithmetic and operational functions.
*/

#include <iostream>
#include "fraction.h"
#include "fraction_exception.h"

// constructors
Fraction::Fraction(int a,int b){
    this->num = a;
    this->den = b;
    if (den < 0){
        this->num = this->num * -1;
        this->den = this->den * -1;
    }
    //this->reduceFraction();

}
Fraction::Fraction(){
    this->num = 0;
    this ->den = 1;
}

//getter, setter methods
void Fraction::setNumbers(int a,int b){
    this->num = a;
    this->den = b;
    if (den < 0){
        this->num = this->num * -1;
        this->den = this->den * -1;
    }
    //this->reduceFraction();
}

float Fraction::getFloat(){
    float a = this->num;
    float b = this->den;
    return a/b;
}

int Fraction::getNum(){
    return this->num;
}

int Fraction::getDen(){
    return this->den;
}


ostream& operator<<(ostream &o, const Fraction& f){
    if (f.num * f.den < 0)
        o << "-";
    if (f.den == 1 || f.num == 0)
        o << abs(f.num);
    
    else if (abs(f.num) > abs(f.den)){
        o << abs(f.num / f.den);
        if (f.num % f.den != 0)
            o << "_" << abs(f.num % f.den) << '/' << abs(f.den);
    }
    else
        o << abs(f.num) << '/' << abs(f.den);

    return o;
}
istream& operator>>(istream &i , Fraction& f){
    char div;
    i >> f.num >> div >> f.den;
    f.reduceFraction();
    return i;
}



// Overloaded assignment operator
Fraction& Fraction::operator=(const Fraction &fraction){
    this->num = fraction.num;
    this->den = fraction.den;
    return *this;
}


// Overloaded relational operators
int Fraction::operator==(const Fraction &fraction) const{
    Fraction f = fraction;
    if (this->num == f.num && this->den == f.den)
        return 1;
    return 0;
}
int Fraction::operator!=(const Fraction &fraction) const{
    Fraction f = fraction;
    if (this->num == f.num && this->den == f.den)
        return 0;
    return 1;
}
int Fraction::operator>(const Fraction &fraction) const{
    int num1 = this->num * fraction.den;
    int num2 = this->den * fraction.num;
    if (num1 > num2)
        return 1;
    return 0;
}
int Fraction::operator>=(const Fraction &fraction) const{
    int num1 = this->num * fraction.den;
    int num2 = this->den * fraction.num;
    if (num1 >= num2)
        return 1;
    return 0;
}
int Fraction::operator<(const Fraction &fraction) const{
    int num1 = this->num * fraction.den;
    int num2 = this->den * fraction.num;
    if (num1 < num2)
        return 1;
    return 0;
}
int Fraction::operator<=(const Fraction &fraction) const{
    int num1 = this->num * fraction.den;
    int num2 = this->den * fraction.num;
    if (num1 <= num2)
        return 1;
    return 0;
}

// Overloaded arithmetic operators
Fraction Fraction::operator+(const Fraction &fraction){
    Fraction finalFrac;
    int num1 = this->num * fraction.den + this->den * fraction.num;
    int den1 = this->den * fraction.den;
    finalFrac.setNumbers(num1, den1);
    finalFrac.reduceFraction();
    return finalFrac;
}
Fraction Fraction::operator-(const Fraction &fraction){
    Fraction finalFrac;
    int num1 = this->num * fraction.den - this->den * fraction.num;
    int den1 = this->den * fraction.den;
    finalFrac.setNumbers(num1, den1);
    finalFrac.reduceFraction();
    return finalFrac;
}
Fraction Fraction::operator*(const Fraction &fraction){
    Fraction finalFrac;
    int num1 = this->num * fraction.num;
    int den1 = this->den * fraction.den;
    finalFrac.setNumbers(num1, den1);
    finalFrac.reduceFraction();
    return finalFrac;
}

Fraction Fraction::operator/(const Fraction &fraction){
    Fraction finalFrac;
    int num1 = this->num * fraction.den;
    int den1 = this->den * fraction.num;
    finalFrac.setNumbers(num1, den1);
    finalFrac.reduceFraction();
    return finalFrac;
}
Fraction& Fraction::operator+=(const Fraction &fraction){
    *this = *this + fraction;
    return *this;

}
Fraction& Fraction::operator-=(const Fraction &fraction){
    *this = *this - fraction;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction &fraction){
    *this = *this * fraction;
    return *this;
}
Fraction& Fraction::operator/=(const Fraction &fraction){
    *this = *this / fraction;
    return *this;
}

void Fraction::reduceFraction(){
    if (this->den == 0)
        throw FractionException();

    bool denneg = 0, numneg = 0;
    if (this->den < 0){
        this->den *= -1;
        denneg = true;
    }
    if (this->num < 0){
        this->num *= -1;
        numneg = true;
    }

    int num1, den1, tmp;
    num1 = this->num;
    den1 = this->den;
    tmp = num1 % den1;
    while (tmp > 0 || tmp < 0){
        num1 = den1;
        den1 = tmp;
        tmp = num1 % den1;
    }
    this->num /= den1;
    this->den /= den1;
    if (denneg)
        this->num *= -1;
    if (numneg)
        this->num *=-1;


}

