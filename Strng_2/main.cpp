
// Class Declaration End

//Class Definition
#include"String.h"
//Class Definition End

//#define NULL_TERMINATED_LINES
//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK

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

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;	//HelloWorld

	str1 += str2;
	cout << str1 << endl;	//HelloWorld  
#endif // OPERATOR_PLUS_CHECK

	String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();
	String str3 = str2;
	str3.print();
	String str4(); //�� ��������� ������ �� ��������� - �� ��������� ������� ��������
	//�������� �������, ������� �� ��������� ������� ���������� � ���������� string
	String str5{}; //����� ����� ������������ �� ���������


}

int StringLength(const char* str)
{
	//������� ������ ������ � ��������, �.�., ��� ����� �������������� ����
	int i = 0;
	for (; str[i]; i++);
	return i;
}