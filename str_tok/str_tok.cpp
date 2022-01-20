#include <iostream>
#include <cstring>
#include "Windows.h"

int main()
{
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[] = "Особенности национальной рыбалки - художественный, комедийный фильм.";

    std::cout << "Разделение строки "" << str << "" на лексемы:\n";
    char* pch = strtok(str, " ,.-"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)

    while (pch != NULL)                         // пока есть лексемы
    {
        std::cout << pch << "\n";
        pch = strtok(NULL, " ,.-");
    }
    delete[] pch;
    return 0;
}