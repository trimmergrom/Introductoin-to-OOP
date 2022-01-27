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
		this->x_1 = x;
	}
	void set_x_2(double x)
	{
		this->x_2 = x;
	}
	void set_y_1(double y)
	{
		this->y_1 = y;
	}
	void set_y_2(double y)
	{
		this->y_2 = y;
	}

	Point(double x_a, double x_b, double y_a, double y_b)
	{
		this->x_1 = x_a;
		this->y_1 = y_a;
		this->x_2 = x_b;
		this->y_2 = y_b;

		std::cout << "Constructor:\t" << this << std::endl;
	}
	Point(double x, double y)
	{
		this->x_1 = x;
		this->y_1 = y;
		
		std::cout << "Constructor:\t" << this << std::endl;
	}

	~Point()
	{
		std::cout << "Destuctor:\t" << this << std::endl;
	}
	double Distance()
	{
		d = sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
		return d;
	}
	void Print()const
	{
		std::cout << "Xa = " << x_1 << " Xb = " << x_2;
		std::cout << "\tYa = " << y_1 << "\tYb = " << y_2 << " Distance AB = " << d << std::endl;
	}

	double dist(Point other)
	{
		double x_dist = this->x_1 - other.x_1;
		double y_dist = this->y_1 - other.y_1;
		double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
		return dist;
	}
};

double Distance(double x_1, double x_2, double y_1, double y_2)
{
	return sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
}

//#define CONSTRUCTORS_CHECK

int main()
{
#ifdef CONSTRUCTORS_CHECK
	Point B(1, 33, 44, 33);
	B.Distance();
	//std::cout << "Distance AB = " << B.Distince();
	B.Print();
	double x_a, x_b, y_a, y_b;
	std::cout << "Enter Xa "; std::cin >> x_a; std::cout << std::endl;
	std::cout << "Enter Ya "; std::cin >> y_a; std::cout << std::endl;
	std::cout << "Enter Xb "; std::cin >> x_b; std::cout << std::endl;
	std::cout << "Enter Yb "; std::cin >> y_b; std::cout << std::endl;
	std::cout << "Distance AB = " << Distance(x_a, x_b, y_a, y_b);
#endif

	Point A(2, 3);
	Point B(7, 8);
	std::cout << "Расстояние от 'A' до 'B': " << A.dist(B) << std::endl;
	std::cout << "Расстояние от 'B' до 'A': " << B.dist(A) << std::endl;
}