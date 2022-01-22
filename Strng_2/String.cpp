
#include"String.h"
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}
String::String(int size) :size(size), str(new char[size] {})
{
	//Благодаря принимаемому параметру size мы можем создавать строки заданного размера
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConst:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	cout << sizeof(str) << endl;

	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;	//Если конструктор выделяет память при помощи оператора new,
	//то деструктор обязательно должен освобождать эту память оператором delete[],
	//в противном случае будет возникать утечка памяти.
	cout << "Destructor:\t" << this << endl;
}

//					Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;

	delete[] this->str;
	//Глубокое копирование (Deep copy)
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

//					Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& rigth)
{
	String result(left.get_size() + rigth.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
	//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < rigth.get_size(); i++)
		result[left.get_size() - 1 + i] = rigth[i];
	//result.get_str()[left.get_size() - 1 + i] = rigth.get_str()[i];
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}