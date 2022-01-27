#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

int StringLength(const char* str);

class String
{
	int size;	//������ ������
	char* str;	//��������� �� ������ � ������������ ������
public:
	explicit String(int size = 80)
	{
		//��������� ������������ ��������� size �� ����� ��������� ������ ��������� �������
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConst:\t" << this << endl;
	}
	String(const char* str)
	{
		//cout << sizeof(str) << endl;
		this->size = StringLength(str) + 1;	//��������� ������ ������ � ������, � ������ �������������� ����.
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//�������� ����������� (Deep copy)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;	//���� ����������� �������� ������ ��� ������ ��������� new,
		//�� ���������� ����������� ������ ����������� ��� ������ ���������� delete[],
		//� ��������� ������ ����� ��������� ������ ������.
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;

		int a = 2;
		int b = 3;
		a = b;
		delete[] this->str;
		//�������� ����������� (Deep copy)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//					Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

//#define NULL_TERMINATED_LINES
//#define BASE_CHECK

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef NULL_TERMINATED_LINES
	'\0';//ASCII-������ � ����� 0.	NULL Terminator
//C-strings - NULL Terminated Lines
//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
/*char str[] = "Hello";
cout << str << endl;
str[2] = 0;
cout << str << endl;
const char* str1 = "World";
str1[2] = 0;*/

	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "������� ������: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
#endif // NULL_TERMINATED_LINES

#ifdef BASE_CHECK
	String str1;
	str1.print();

	//String str2 = 25;	//�������������� int � String ��������� ��� ������ explicit
	String str2(25);	//explicit ����������� ����� ������� ������ ���
	str2.print();

	cout << sizeof("Hello") << endl;
	cout << "StringLength:" << StringLength("Hello") << endl;;

	String str3 = "Hello";
	str3.print();

	str3 = str3;

	String str4 = str3;	//CopyConstructor
	str4.print();

	String str5;
	str5 = str4;	//CopyAssignment
	str5.print();
#endif // BASE_CHECK

	//String str1 = "Hello";
	//String str2 = "World";
	//String str3 = str1 + str2;
	//cout << str3 << endl;	//HelloWorld

	//str1 += str2;
	//cout << str1 << endl;	//HelloWorld
}

int StringLength(const char* str)
{
	//������� ������ ������ � ��������, �.�., ��� ����� �������������� ����
	int i = 0;
	for (; str[i]; i++);
	return i;
}