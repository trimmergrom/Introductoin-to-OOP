#include<iostream>
#include "Point.h"
using namespace std;


//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGMENT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//��������� ���������� 'a' ���� 'int'
	Point A;//��������� ���������� 'A' ���� 'Point'
			//������� ������ (���������) ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//������� ��������� �� ������ ����� ���������
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;	//DefaultConstructor
	double x, y;
	//cout << "������� ���������� �����: "; cin >> x >> y;
	//A.set_x(x);
	//A.set_y(y);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(22, 33);
	B.print();

	Point C = 5;	//Single-argument constructor
	C.print();

	Point D(0, 123);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	cout << "\n---------------------------\n";
	cout << "���������� �� ����� 'A' �� ����� 'B': " << A.distance(B) << endl;
	cout << "\n---------------------------\n";

	cout << "���������� �� ����� 'B' �� ����� 'A': " << B.distance(A) << endl;
	cout << "\n---------------------------\n";

	cout << "���� ����� �, �" << distance(A, B) << endl;
	cout << "\n---------------------------\n";

	cout << "���� ����� �, �" << distance(B, A) << endl;
	cout << "\n---------------------------\n";

#endif // DISTANCE_CHECK
	/*Point A(2, 3);
	Point B = A; // copyconstructor
	B.print();
	Point C;
	C = B; // CopyAss
	/C.print();*/
#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	cout << "\n-------------------------\n";
	A = B = C = Point(7, 8);
	cout << "\n-------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK


	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();
	A += B;
	A.print();
	C++;
	C.print();
	A = B++;
	A.print();
	B.print();
	B.set_x(123);
	B.set_y(234);
	B.print();


	

	
}

/*
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
*/
/*
1. ������������ (Encapsulation);
������������ �������:
private:	�������� ������ ������ ������.
public:
protected:
get/set-������

get (�����, ��������)	 - ��������� ������ � ���������� ������ �� ������,
						   �.�., ���������� �������� �������� ��� ��� ����
						   ����������-�����.
set (������, ����������) - ��������� ������ � ���������� ������ �� ������,
						   �.�., ��������� ������ �������� ��� ��� ����
						   ����������-�����.



2. ������������ (Inheritance);
3. �����������  (Polymorphism);
*/

/*
				SPECIAL MEMBERS
Constructor - ��� �����, ������� ������� ������. � ������, �������� ������ ��� ������,
			  � �������������� ��� ���������� �����.
~Destructor	-
operator=
*/

/*
------------------------------------------------
type name(parameters)
{
	//Function body:
	......
}
------------------------------------------------
*/