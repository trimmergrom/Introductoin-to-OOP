#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
//#define DEBUG

class Fraction;
Fraction operator*(Fraction left, Fraction rigth);
Fraction operator/(Fraction left, Fraction rigth);

class Fraction
{
    int integer;
    int numerator;
    int denominator;
    double decimal;
public:

    int get_integer()const;
    int get_numerator()const;
    int get_denominator()const;
    double get_decimal()const;
    void set_integer(int integer);
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    void set_decimal(double decimal);
    Fraction(int integer, int numerator, int denominator);
    Fraction();
    explicit Fraction(int integer);
    Fraction(double decimal);
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& other);
    ~Fraction();

    Fraction& operator=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);
    Fraction& operator++(int);
    Fraction& operator--(int);
    Fraction& operator++();
    Fraction& operator--();


    //            Type-cast operators:
    explicit operator int()const;
    explicit operator double()const;

    Fraction& to_proper();
    Fraction& to_improper();
    Fraction& reduce();
    Fraction inverted();
    void print()const;
};
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& in, Fraction& obj);
