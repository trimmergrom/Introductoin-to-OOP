#include "Fraction.h"


int Fraction::get_integer()const
{
    return integer;
}
int Fraction::get_numerator()const
{
    return numerator;
}
int Fraction::get_denominator()const
{
    return denominator;
}
double Fraction::get_decimal()const
{
    return decimal;
}
void Fraction::set_integer(int integer)
{
    this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
    this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
    if (denominator <= 0)denominator = 1;
    this->denominator = denominator;
}
void Fraction::set_decimal(double decimal)
{
    this->decimal = decimal;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
    this->integer = integer;
    this->numerator = numerator;
    set_denominator(denominator);
#ifdef DEBUG
    cout << "Constructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction()
{
    this->integer = 0;
    this->numerator = 0;
    this->denominator = 1;
#ifdef DEBUG
    cout << "DefaultConstruct:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int integer)
{
    this->integer = integer;
    this->numerator = 0;
    this->denominator = 1;
#ifdef DEBUG
    cout << "1ArgConstructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(double decimal)
{
    /*this->integer = (int)decimal;
    int p = 0;
    double delta = decimal - (int)decimal;
    while ((int)delta / delta < 0.99)
    {
        delta *= 10;
        p++;
    }
    this->numerator = delta;
    this->denominator = (pow(10, p));*/
    decimal += 1e-11;
    integer = decimal;
    decimal -= integer;
    denominator = 1e+9;
    numerator = decimal * denominator;
    reduce();

#ifdef DEBUG
    cout << "1ArgDcmConstructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int numerator, int denominator)
{
    this->integer = 0;
    this->numerator = numerator;
    set_denominator(denominator);
#ifdef DEBUG
    cout << "Constructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
#ifdef DEBUG
    cout << "Copyconstructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::~Fraction()
{
#ifdef DEBUG
    cout << "Destructor\t" << this << endl;
#endif // DEBUG
}

Fraction& Fraction::operator=(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
#ifdef DEBUG
    cout << "CopyAssigment:\t" << this << endl;
#endif // DEBUG
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
    return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
    return *this = *this / other;
}
Fraction& Fraction::operator++(int) //Postfix
{
    this->integer = integer++;
    this->numerator = numerator;
    this->denominator = denominator;
    return *this;
}
Fraction& Fraction::operator--(int) //Postfix
{
    this->integer = integer--;
    this->numerator = numerator;
    this->denominator = denominator;
    return *this;
}
Fraction& Fraction::operator++() //Prefix
{
    this->integer = integer++;
    this->numerator = numerator;
    this->denominator = denominator;
    return *this;
}
Fraction& Fraction::operator--() //Prefix
{
    this->integer = integer--;
    this->numerator = numerator;
    this->denominator = denominator;
    return *this;
}


//            Type-cast operators:
Fraction::operator int()const
{
    return integer;
}
Fraction::operator double()const
{
    return integer + (double)numerator / denominator;
}

Fraction& Fraction::to_proper()
{
    integer += numerator / denominator;
    numerator %= denominator;
    return *this;
}
Fraction& Fraction::to_improper()
{
    numerator += integer * denominator;
    integer = 0;
    return *this;
}
Fraction& Fraction::reduce()
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
Fraction Fraction::inverted()
{
    return Fraction(denominator, numerator);
}
void Fraction::print()const
{
    if (integer)cout << integer;
    if (numerator)
    {
        if (integer)cout << "(";
        cout << numerator << "/" << denominator;
        if (integer)cout << ")";
    }
    else if (integer == 0)cout << 0;
    cout << endl;
}
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
    //if (obj.get_decimal())cout << obj.get_decimal();
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
std::istream& operator>>(std::istream& in, Fraction& obj)
{
    /*int integer, numerator, denominator;
    in >> integer >> numerator >> denominator;
    obj.set_integer(integer);
    obj.set_numerator(numerator);
    obj.set_denominator(denominator);
    return in;*/

    /*cout << "Enter decimal: "; in >> obj.decimal;
        if (obj.decimal > 0) { return in; }
        else
        {
        cout << "Enter integer:\t";  in >> obj.integer;
        cout << "Enter numerator:\t";  in >> obj.numerator;
        cout << "Enter denominator:\t";  in >> obj.denominator;
    return in;
        }    */
    obj = Fraction();
    const int SIZE = 256;
    char buffer[SIZE] = {};
    //in >> buffer;
    in.getline(buffer, SIZE);
    char delimiters[] = "/( )";
    char* number[3] = {};//Save numbers out buffer
    int n = 0; //coutn numbers out bufffer
    for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
    {
        number[n++] = pch;
    }
    switch (n)
    {
    case 1: obj.set_integer(atoi(number[0])); break;
    case 2: obj.set_numerator(atoi(number[0]));
        obj.set_denominator(atoi(number[1])); break;
    case 3: obj.set_integer(atoi(number[0]));
        obj.set_numerator(atoi(number[1]));
        obj.set_denominator(atoi(number[2])); break;
    }
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
        result.set_numerator(left.get_numerator() * rigth.get_denominator() +
            rigth.get_numerator() * left.get_denominator());
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
        result.set_numerator(left.get_numerator() * rigth.get_denominator() -
            rigth.get_numerator() * left.get_denominator());
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
    while ((int)delta / delta < 0.99)
    {
        delta *= 10;
        p++;
    }
    result.set_numerator(delta);
    result.set_denominator(pow(10, p));
    return result;
}