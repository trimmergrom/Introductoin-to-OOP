#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int StringLength(const char* str);

//#define NULL_TERMINATED_LINES
//#define BASE_CHEK

class String
{
	int size;
	char* str;
public:
	int get_size()
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	void set_size()
	{
		this->size = size;
	}
	void set_str()
	{
		this->str = str;
	}

	explicit String(int size = 80) //target size
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = StringLength(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	/*String operator+(const String& other)
	{
		String result(size - 1 + other.size);
		for (int i = 0; i < size - 1; i++)result.str[i] = str[i];
		for (int i = size - 1; i < size - 1 + other.size; i++)result.str[i] = other.str[i - other.size + 1];

		return result;
	}*/

	/*String& operator+=(const String& other)
	{
		char* buffer = new char[size - 1 + other.size]{};
		for (int i = 0; i < size; i++)buffer[i] = str[i];
		delete[] this->str;
		this->str = buffer;
		this->size = size - 1 + other.size;
		for (int i = size - other.size; i < size; i++)
		{
			this->str[i] = other.str[i - other.size + 1];
		}
		return *this;
	}*/
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	//int i = 0;
	//for (; str[i]; i++) os << str[i];
	return os << obj.get_str();
}



int main()
{
#ifdef NULL_TERMINATED_LINES
	// setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*char str[] = "Hello";
	cout << str << endl;
	str[2] = 0;
	cout << str << endl;
	const char* str1 = "World";
	cout << str1 << endl;*/
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "input string";
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str;
#endif // NULL_TERMINATED_LINES
#ifdef BASE_CHEK
	String str1;
	str1.print();
	String str2(25);
	str2.print();
	String str3 = "Hello";
	str3.print();
	str3 = str3;
	cout << "StringLength:\t" << StringLength("Hello") << endl;
	String str4 = str3;//CopyConstructor
	str4.print();

	String str5;
	str5 = str4;//CopyAssignment
	str5.print();
#endif // BASE_CHEK

	String str1 = "Hello";
	String str2 = "World";
	/*cout << str1 << endl;
	cout << str2 << endl;*/
	str1.print();
	str2.print();
	cout << "------------str3= str1+str2=---------------\n";
	//String str3 = str1 + str2;
	//str3.print();
	//(str1 + str2).print();
	cout << str1 + str2 << endl;
	cout << "------------str1 += str2-------------------\n";
	//str1 += str2;
	str1.print();
}
int StringLength(const char* str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
