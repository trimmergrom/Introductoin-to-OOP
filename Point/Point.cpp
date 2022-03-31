#include "Point.h"
double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;//Encapsulation DONE
	//this - ýòî óêàçàòåëü íà îáúåêò, äëÿ êîòîðîãî âûçûâàåòñÿ ìåòîä
	//Èçíóòðè ìåòîäà íåâîçìîæíî óçíàòü èìÿ îáúåêòà, äëÿ êîòîðîãî îí âûçûâàåòñÿ
	//ÍÎ âñåãäà ìîæíî óçíàòü àäðåñ ýòîãî îáúåêòà.
}
void Point::set_y(double y)
{
	this->y = y;
}

//					Constructors:
Point::Point()
{
	x = y = 0;
	cout << "DefaultConstructor:\t" << this << endl;
}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "Constructor:\t" << this << endl;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "Copyconstructor: " << this << endl;
}
Point::~Point()
{
	cout << "Destructor:\t" << this << endl;
}
//       Operators:
Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Point& Point::operator+=(const Point& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;

}
Point& Point::operator++() //Prefix
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)
{
	Point old = *this;
	x++;
	y++;
	return old;
}
Point& Point::operator()(double x, double y)
{
	set_x(x);
	set_y(y);
	return *this;
}

//				Methods:
double Point::distance(const Point& other)const
{
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
void Point::print()const
{
	cout << "X = " << x << "\tY = " << y << endl;
}

Point operator+(const Point& left, const Point& rigth)
{
	Point result;
	result.set_x(left.get_x() + rigth.get_x());
	result.set_y(left.get_y() + rigth.get_y());
	return result;
}
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	cout << obj.get_x();
	cout << obj.get_y();	
	return os;
}