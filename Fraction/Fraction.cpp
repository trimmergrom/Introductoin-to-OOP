

#include <iostream>
#include <Windows.h>

class Fraction
{
    int A;
    int a;
    unsigned int b;

public:
    
    int get_A()const
    {
        return A;
    }
    int get_a()const
    {
        return a;
    }
    unsigned int get_b()const
    {
        return b;
    }
    void set_A(int a)
    {
        this->A = A;
    }
    void set_a(int a)
    {
        this->a = a;
    }
    void set_b(unsigned int b)
    {
        this->b = b;
        b > 0;
    }
    Fraction()
    {
        a = b = 0;
        //std::cout << "DefaultConstructor:\t" << this << std::endl;
    }
    Fraction(int a, unsigned int b)
    {
        this->a = a;
        this->b = b;
        //std::cout << "Constructor\t" << this << std::endl;
    }
    Fraction(int A, int a, unsigned int b)
    {
        this->A = A;
        this->a = a;
        this->b = b;
       //std::cout << "Constructor_1\t" << this << std::endl;
    }
    ~Fraction()
    {
        //std::cout << "Destructor\t" << this << std::endl;
    }
   
    void print()const
    {
        std::cout << a << "/" << b << std::endl;
    }
    void print_1()const
    {
        std::cout << A << "(" << a << "/" << b << ")" << std::endl;
    }

    Fraction& reduce()
    {
        int a_gcf = this->a; int b_gcf = this->b;
        while (a_gcf != 0 && b_gcf != 0)
        {
            if (a_gcf > b_gcf) { a_gcf = a_gcf % b_gcf; }
            else { b_gcf = b_gcf % a_gcf; }
        }
        int gcf = a_gcf + b_gcf;
        this->a = this->a / gcf;
        this->b = this->b / gcf;        
        return  *this;
    }
    Fraction& to_proper()
    {        
        this->A = this->a / this->b;
        this->a = this->a - this->A * this->b;
        return *this;
    }
    Fraction& to_improper()
    {
        this->a = this->A * this->b + this->a;
        return *this;
    }
    bool operator>(Fraction& other)
    {        
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 > comp_2) { return  true; }
        else return false;        
    }
    bool operator<(Fraction& other)
    {
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 < comp_2) { return true; }
        else return false;
    }
    bool operator<=(Fraction& other)
    {
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 <= comp_2) { return true; }
        else return false;
    }
    bool operator>=(Fraction& other)
    {
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 >= comp_2) { return true; }
        else return false;
    }
    bool operator==(Fraction& other)
    {
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 == comp_2) { return true; }
        else return false;
    }
    bool operator!=(Fraction& other)
    {
        int comp_1 = this->a * other.b;
        int comp_2 = this->b * other.a;
        if (comp_1 != comp_2) { return true; }
        else return false;
    }    

    Fraction& operator+=(const Fraction& other)
    {
        if (this->b == other.b)
        {
            this->a = this->a + other.a;
            this->b;
        }
        else
        {
        this->a = this->a*other.b + other.a*this->b;
        this->b = other.b*this->b;
        }
        return *this;
    }
    Fraction& operator-=(const Fraction& other)
    {
        if (this->b == other.b)
        {
            this->a = this->a - other.a;
            this->b;
        }
        else
        {
            this->a = this->a * other.b - other.a * this->b;
            this->b = other.b * this->b;
        }
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
       if(left.get_b() == rigth.get_b())
       {
           result.set_a(left.get_a() + rigth.get_a());
           result.set_b(left.get_b());
       }
       else
       {
           result.set_a(left.get_a() * rigth.get_b() + rigth.get_a() * left.get_b());
           result.set_b(left.get_b() * rigth.get_b());
       }

       return result;
    }
  Fraction operator-(const Fraction& left, const Fraction& rigth)
    {
       Fraction result;
       if (left.get_b() == rigth.get_b())
       {
           result.set_a(left.get_a() - rigth.get_a());
           result.set_b(left.get_b());
       }
       else
       {
            result.set_a(left.get_a()*rigth.get_b() - rigth.get_a()*left.get_b());
            result.set_b(left.get_b() * rigth.get_b());
       }
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
    Fraction C(2, 7); std::cout << "C = "; C.print();
    Fraction D(4, 7); std::cout << "D = "; D.print();    
    std::cout << "C + D = "; (C + D).print();
    std::cout << "=======================================" << std::endl;
    Fraction E(2, 7); std::cout << "E = "; E.print();
    Fraction F(4, 7); std::cout << "F = "; F.print();
    std::cout << "E += F = "; (E += F).print();
    std::cout << "=======================================" << std::endl;
    Fraction G(2, 7); std::cout << "G = "; G.print();
    Fraction K(4, 5); std::cout << "K = "; K.print();
    std::cout << "G - K = "; (G - K).print();
    std::cout << "=======================================" << std::endl;
    Fraction L(2, 7); std::cout << "L = "; L.print();
    Fraction M(4, 5); std::cout << "M = "; M.print();   
    std::cout << "L -= M = "; (L -= M).print();
    std::cout << "=======================================" << std::endl;
    Fraction P(2, 7); std::cout << "P = "; P.print();
    Fraction R(4, 5); std::cout << "R = "; R.print();
    std::cout << "P * R = "; (P * R).print();
    std::cout << "=======================================" << std::endl;
    Fraction S(2, 7); std::cout << "S = "; S.print();
    Fraction T(4, 5); std::cout << "T = "; T.print();
    std::cout << "S *= T = "; (S *= T).print();
    std::cout << "=======================================" << std::endl;
    Fraction Q(2, 7); std::cout << "Q = "; Q.print();
    Fraction Z(4, 5); std::cout << "Z = "; Z.print();   
    std::cout << "Q / Z = "; (Q / Z).print();
    std::cout << "=======================================" << std::endl;
    Fraction X(2, 7); std::cout << "X = "; X.print();
    Fraction Y(4, 5); std::cout << "Y = "; Y.print();   
    std::cout << "X /= Y = "; (X /= Y).print();
    std::cout << "=======================================" << std::endl;    
    Fraction A(24, 12, 18);
    Fraction B(23, 5);
    std::cout << "B = "; B.print(); B.to_proper(); std::cout << "B.to_proper = ";  B.print_1();
    std::cout << "A = "; A.print_1(); std::cout << "A.to_improper = ";  A.to_improper(); A.print();
    std::cout << "A.reduce = "; A.reduce(); A.print();
    std::cout << "=======================================" << std::endl;
    return 0;
} 