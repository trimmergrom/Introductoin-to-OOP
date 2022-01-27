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
std::istream& operator>>(std::istream& in, Fraction& obj);

class Fraction
{
    int integer;
    int numerator;
    int denominator;
public:
    
    int get_integer()const
    {
        return integer;
    }
    int get_numerator()const
    {
        return numerator;
    }
    int get_denominator()const
    {
        return denominator;
    }
    void set_integer(int integer)
    {
        this->integer = integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        if (denominator <= 0)denominator = 1;
        this->denominator = denominator;
    }
    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        set_denominator(denominator);
#ifdef DEBUG
        cout << "Constructor:\t" << this << endl;
#endif // DEBUG
    }
    Fraction()
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
#ifdef DEBUG
        cout << "DefaultConstruct:\t" << this << endl;
#endif // DEBUG
    }
    explicit Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
#ifdef DEBUG
        cout << "1ArgConstructor:\t" << this << endl;
#endif // DEBUG
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
#ifdef DEBUG
        cout << "Constructor:\t" << this << endl;
#endif // DEBUG
    }
    Fraction(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
#ifdef DEBUG
        cout << "Copyconstructor:\t" << this << endl;
#endif // DEBUG
    }
    ~Fraction()
    {
#ifdef DEBUG
        cout << "Destructor\t" << this << endl;
#endif // DEBUG
    }
    
    Fraction& operator=(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
#ifdef DEBUG
        cout << "CopyAssigment:\t" << this << endl;
#endif // DEBUG
        return *this;
    }
    Fraction& operator*=(const Fraction& other)
    {
        return *this = *this * other;
    }
    Fraction& operator/=(const Fraction& other)
    {
        return *this = *this / other;
    }
    Fraction& operator++(int) //Postfix
    {
        this->integer = integer++;
        this->numerator = numerator;
        this->denominator = denominator;
        return *this;
    }
    Fraction& operator--(int) //Postfix
    {
        this->integer = integer--;
        this->numerator = numerator;
        this->denominator = denominator;
        return *this;
    }
    Fraction& operator++() //Prefix
    {
        this->integer = integer++;
        this->numerator = numerator;
        this->denominator = denominator;
        return *this;
    }
    Fraction& operator--() //Prefix
    {
        this->integer = integer--;
        this->numerator = numerator;
        this->denominator = denominator;
        return *this;
    }
    
    
    //            Type-cast operators:
    explicit operator int()const
    {
        return integer;
    }
    explicit operator double()const
    {
        return integer + (double)numerator / denominator;
    }

    Fraction& to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
        return *this;
    }
    Fraction& to_improper()
    {
        numerator += integer * denominator;
        integer = 0;
        return *this;
    }
    Fraction& reduce()
    {
        int numerator_gcf = (this->numerator); unsigned int denominator_gcf = this->denominator;
        while (numerator_gcf != 0 && denominator_gcf != 0)
        {
            if (abs(numerator_gcf) > denominator_gcf) { numerator_gcf = abs(numerator_gcf) % denominator_gcf; }
            else { denominator_gcf = denominator_gcf % abs(numerator_gcf); }
        }
        int gcf = numerator_gcf + denominator_gcf;
        if (this->numerator < 0) { this->numerator = -(abs(this->numerator) / gcf); }
        else { this->numerator = this->numerator / gcf; }
        this->denominator = this->denominator / gcf;
        return  *this;
    }
    Fraction inverted()
    {
        return Fraction(denominator, numerator);
    }
    void print()const
    {
        if (integer)cout << integer;
        if (numerator)
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        else if (integer==0)cout << 0;
        cout << endl;
    }
    friend std::istream& operator>>(std::istream&, Fraction&);
};

Fraction operator*(Fraction left, Fraction rigth)
{
    left.to_improper();
    rigth.to_improper();   
    return Fraction(left.get_numerator() * rigth.get_numerator(),
        left.get_denominator() * rigth.get_denominator()).to_proper();
}
Fraction operator/(Fraction left, Fraction rigth)
{
    left.to_improper();
    rigth.to_improper();
    return left * rigth.inverted();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    if (obj.get_integer())cout << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())cout << "(";
        cout << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())cout << ")";
    }
    else if (obj.get_integer() == 0)cout << 0;
    return os;
}
std::istream& operator>>(std::istream &in, Fraction& obj)
{
    cout << "Enter integer:\t";  in >> obj.integer;
    cout << "Enter numerator:\t";  in >> obj.numerator;
    cout << "Enter denominator:\t";  in >> obj.denominator;    
    return in;
}
Fraction operator+(const Fraction& left, const Fraction& rigth)
{
    Fraction result;
    if (left.get_denominator() == rigth.get_denominator())
    {
        result.set_numerator(left.get_numerator() + rigth.get_numerator());
        result.set_denominator(left.get_denominator());
    }
    else
    {
        result.set_numerator(left.get_numerator() * rigth.get_denominator() + rigth.get_numerator() * left.get_denominator());
        result.set_denominator(left.get_denominator() * rigth.get_denominator());
    }
    return result;
}
Fraction operator-(const Fraction& left, const Fraction& rigth)
{
    Fraction result;
    if (left.get_denominator() == rigth.get_denominator())
    {
        result.set_numerator(left.get_numerator() - rigth.get_numerator());
        result.set_denominator(left.get_denominator());
    }
    else
    {
        result.set_numerator(left.get_numerator() * rigth.get_denominator() - rigth.get_numerator() * left.get_denominator());
        result.set_denominator(left.get_denominator() * rigth.get_denominator());
    }
    return result;
}
Fraction dcm_to_frc(double dcm)
{
    Fraction result;
    int p = 0;    
        result.set_integer((int)dcm);
        double delta = dcm - (int)dcm;
        while ((int)delta/delta < 0.99)
        {
            delta *= 10;
            p++;
        }
        result.set_numerator(delta);    
        result.set_denominator(pow(10, p));
    return result;
}

//#define CONSTRUCTORS_CHECK
#define CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER_TYPES


int main()
{
#ifdef CONSTRUCTORS_CHECK
    Fraction A;
    A.print();
    Fraction B = 5;
    B.print();
    Fraction D(3, 2, 4);
    D.print();
    Fraction E = D;
    E.print();
#endif // CONSTRUCTORS_CHECK

    Fraction A(2, 3, 4);
    Fraction B(3, 4, 5);
    Fraction C = A * B;   
    Fraction T(3, 4);
    
    cout << T << endl;
    A.print();
    B.print();
    C.print();
    (A / B).print();
    (A *= B).print();
    cout << "\n--------------------Postfix----------------------------------\n";
    cout << "B = " << B << endl;
    cout << "B++ = " << B++ << endl;
    cout << "T = " << T << endl;
    cout << "T++ = " << T++ << endl;
    cout << "T-- = " << T-- << endl;
    cout << "B-- = " <<B-- << endl;
    cout << "\n-------------------Prefix-----------------------------------\n";
    cout << "B = " << B << endl;
    cout << "++B = " << ++B << endl;
    cout << "--B = " << --B << endl;
    cout << "++T = " << ++T << endl;
    cout << "--T = " << --T << endl;    
    cout << "\n------------------------------------------------------------\n";
   
    Fraction E(2, 3, 4);
    double b = (double)E;
    cout << b << endl;
    Fraction K(dcm_to_frc(b));
    cout << K << endl;
    
    //cout << "Enter K = "; std::cin >> K;

    //cout << K.to_improper() << endl;

    
}

