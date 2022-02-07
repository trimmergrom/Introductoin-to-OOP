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
	int a;	//Объявляем переменную 'a' типа 'int'
	Point A;//Объявляем переменную 'A' типа 'Point'
			//Создаем объект (экземпляр) структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//Создаем указатель на объект нашей структуры
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;	//DefaultConstructor
	double x, y;
	//cout << "Введите координаты точки: "; cin >> x >> y;
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
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << "\n---------------------------\n";

	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << "\n---------------------------\n";

	cout << "Раст между А, В" << distance(A, B) << endl;
	cout << "\n---------------------------\n";

	cout << "Раст между В, А" << distance(B, A) << endl;
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
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
*/
/*
1. Инкапсуляция (Encapsulation);
Модификаторы доступа:
private:	доступны только внутри класса.
public:
protected:
get/set-методы

get (взять, получить)	 - открывают доступ к переменным членам на чтение,
						   т.е., поззволяют получить значение той или иной
						   переменной-члена.
set (задать, установить) - открывают доступ в переменным членам на запись,
						   т.е., позволяют задать значение той или иной
						   переменной-члена.



2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
*/

/*
				SPECIAL MEMBERS
Constructor - это метод, который создает объект. А именно, выделяет память под объект,
			  и инициализирует его переменные члены.
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