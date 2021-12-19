

#include <iostream>d

class Fraction
{
    //int A;
    int a;
    int b;
    
public:
   /* int get_A()const
    {
        return A;
    }*/
    int get_a()const
    {
        return a;
    }
    int get_b()const
    {
        return b;
    }
   /* void set_A(int a)
    {
        this->A = A;
    }*/
    void set_a(int a)
    {
        this->a = a;
    }
    void set_b(int b)
    {
        this->b = b;
    }
    Fraction()
    {
        a = b = 0;
        //std::cout << "DefaultConstructor:\t" << this << std::endl;
    }
    Fraction(int a, int b)
    {
        this->a = a;
        this->b = b;
        //std::cout << "Constructor\t" << this << std::endl;
    }
    /*Fraction(int A, int a, int b)
    {
        this->A = A;
        this->a = a;
        this->b = b;
        std::cout << "Constructor_1\t" << this << std::endl;
    }*/
    ~Fraction()
    {
        //std::cout << "Destructor\t" << this << std::endl;
    }
   
    void print()const
    {
        std::cout << a << " / " << b << std::endl;
    }
    void print_1()const
    {
        std::cout << "(" << a << " / " << b << ")" << std::endl;
    }
    Fraction& operator+=(const Fraction& other)
    {
        this->a = this->a*other.b + other.a*this->b;
        this->b = other.b*this->b;
        return *this;
    }
    Fraction& operator-=(const Fraction& other)
    {
        this->a = this->a*other.b - other.a*this->b;
        this->b = other.b*this->b;
        return *this;
    }
    Fraction& operator*=(const Fraction& other)
    {
        this->a = this->a*other.a;
        this->b = this->b*other.b;
        return *this;
    }
    Fraction& operator/=(const Fraction& other)
    {
        this->a *= other.b;
        this->b *= other.a;
        return *this;
    }
};
  Fraction operator+(const Fraction& left, const Fraction& rigth)
    {
       Fraction result;
       result.set_a(left.get_a()*rigth.get_b() + rigth.get_a()*left.get_b());
       result.set_b(left.get_b() * rigth.get_b());
       return result;
    }
  Fraction operator-(const Fraction& left, const Fraction& rigth)
    {
       Fraction result;
       result.set_a(left.get_a()*rigth.get_b() - rigth.get_a()*left.get_b());
       result.set_b(left.get_b() * rigth.get_b());
       return result;
    }
  Fraction operator*(const Fraction& left, const Fraction& rigth)
    {
       Fraction result;
       result.set_a(left.get_a() * rigth.get_a());
       result.set_b(left.get_b() * rigth.get_b());
       return result;
    }
  Fraction operator/(const Fraction& left, const Fraction& rigth)
    {
       Fraction result;
       result.set_a(left.get_a() * rigth.get_b());
       result.set_b(left.get_b() * rigth.get_a());
       return result;
    }

int main()
{
    Fraction A(1, 3);
    Fraction E(1, 3);
    Fraction C(1, 3);
    Fraction B(2, 7);
    Fraction R(2, 7);
    Fraction D(2, 7);
    
    

    A.print();    
    B.print();    
    //std::cout << "A + B = "; (A + B).print();
    //std::cout << "A += B = "; (A += B).print();
    //std::cout << "A - B = "; (E - R).print();
    std::cout << "A -= B = "; (A -= B).print();
    std::cout << "B - A = "; (R - E).print();
    std::cout << "B -= A = "; (R -= E).print();
    //std::cout << "A * B = "; (C * D).print();
    //std::cout << "A *= B is "; (C *= D).print();
    std::cout << "A / B = "; (C / D).print();
    std::cout << "A /= B is "; (C /= D).print();
   

    return 0;
} 