#include <iostream>
#include <cmath>

class Point
{
	double x_1;
	double x_2;
	double y_1;
	double y_2;
	double d;
	
public:
	
	double get_x_1()const
	{
		return x_1;
	}
	double get_x_2()const
	{
		return x_2;
	}
	double get_y_1()const
	{
		return y_1;
	}
	double get_y_2()const
	{
		return y_2;
	}
	double get_d()const
	{
		return d;
	}
	
	void set_x_1(double x)
	{
		this -> x_1 = x;
	}
	void set_x_2(double x)
	{
		this-> x_2 = x;
	}
	void set_y_1(double y)
	{
		this -> y_1 = y;
	}
	void set_y_2(double y)
	{
		this-> y_2 = y;
	}
	/*Point()
	{
		x = y = 0;
		std::cout << " DefaultConstructor:\t" << this << std::endl;
	}*/
	Point(double x_a, double x_b, double y_a, double y_b)
	{
		this->x_1 = x_a;
		this->y_1 = y_a;
		this->x_2 = x_b;
		this->y_2 = y_b;
		
		std::cout << "Constructor:\t" << this << std::endl;
	}
	~ Point()
	{
		std::cout << "Destuctor:\t" << this << std::endl;
	}
	double Distination()
	{
		d = sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
		return d;
	}
	void Print()const
	{
		std::cout << "xa = " << x_1 << " xb = " << x_2; /*<< std::endl*/;
		std::cout << "\tya = " << y_1 << "\tyb = " << y_2 << " Dist = " << d << std::endl;
	}
};
#define struct_POINT
int main()
{	

	Point B(1, 33, 44, 33);
	B.Distination();
	B.Print();
	


	//A.set_x(2);
	//A.set_y(3);

	//std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
}