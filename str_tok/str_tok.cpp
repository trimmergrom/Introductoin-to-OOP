#include <iostream>
#include <cstring>
#include "Windows.h"

int main()
{
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[] = "����������� ������������ ������� - ��������������, ���������� �����.";

    std::cout << "���������� ������ "" << str << "" �� �������:\n";
    char* pch = strtok(str, " ,.-"); // �� ������ ��������� ������� ����������� (������, �������, �����, ����)

    while (pch != NULL)                         // ���� ���� �������
    {
        std::cout << pch << "\n";
        pch = strtok(NULL, " ,.-");
    }
    delete[] pch;
    return 0;
}