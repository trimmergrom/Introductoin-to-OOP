#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
int StringLength(const char* str);
/// <summary>
/// //////////////Class Declaration
/// </summary>
class String;
String operator+(const String& left, const String& rigth);

class String
{
	int size;	//Размер строки
	char* str;	//Указатель на строку в динамической памяти
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//					Operators:
	String& operator=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);
	String& operator+=(const String& other);

	//					Methods:
	void print()const;
};