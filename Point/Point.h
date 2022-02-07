#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;


#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	//					Constructors:
	Point();
	Point(double x, double y);
	Point(const Point& other);
	~Point();
	//       Operators:
	Point& operator=(const Point& other);
	Point& operator+=(const Point& other);
	Point& operator++();
	Point operator++(int);
	Point& operator()(double x, double y);

	//				Methods:
	double distance(const Point& other)const;
	void print()const;
};
Point operator+(const Point& left, const Point& rigth);
double distance(const Point& A, const Point& B);
