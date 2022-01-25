#include "Fraction.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);


    Fraction B(3, 4, 5);
    Fraction T(3, 4);
    Fraction K;
    Fraction R;
    Fraction S(2.89);

    double decimal;



    cout << "Enter K = " << endl; cin >> K;
    //cout << K << endl;

    cout << K;
   
    
    cout << "\n--------------------Decimal----------------------------------\n";
    cout << "decimal to fraction: ";
   // S.print();
    cout << S << endl;


    cout << "\n--------------------Postfix----------------------------------\n";
    cout << "B = " << B << endl;
    cout << "B++ = " << B++ << endl;
    cout << "T = " << T << endl;
    cout << "T++ = " << T++ << endl;
    cout << "T-- = " << T-- << endl;
    cout << "B-- = " << B-- << endl;
    cout << "\n-------------------Prefix-----------------------------------\n";
    cout << "B = " << B << endl;
    cout << "++B = " << ++B << endl;
    cout << "--B = " << --B << endl;
    cout << "++T = " << ++T << endl;
    cout << "--T = " << --T << endl;
    cout << "\n------------------------------------------------------------\n";

}


