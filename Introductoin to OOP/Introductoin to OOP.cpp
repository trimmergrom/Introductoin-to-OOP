#include <iostream>

class Point
{
	double x;
	double y;
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
}A,B,C;
#define struct_POINT
int main()
{
	Point A;
	A.set_x(2);
	A.set_y(3);

	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
}
