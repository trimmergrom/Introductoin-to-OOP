#include <iostream>

class Point
{
	double x;
	double y;
	double c;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	/*Point()
	{
		x = y = 0;
		std::cout << " DefaultConstructor:\t" << this << std::endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constructor:\t" << this << std::endl;
	}
	~ Point()
	{
		std::cout << "Destuctor:\t" << this << std::endl;
	}
	void Print()const
	{
		std::cout << "x = " << x /*<< std::endl*/;
		std::cout << "\ty = " << y << std::endl;
	}
};
#define struct_POINT
int main()
{
	Point A;
	double x, y;
	A.Print();

	Point B(22, 33);
	B.Print();
	Point C = 5;
	C.Print();
	Point D(0, 123);
	D.Print();


	//A.set_x(2);
	//A.set_y(3);

	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
}