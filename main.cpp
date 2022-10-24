#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "int: " << sizeof(int) << "\n" << "short int: " << sizeof(short int) << "\n"
    << "long int: " << sizeof(long int) << "\n" << "float: " << sizeof(float) << "\n"
    << "double: " << sizeof(double) << "\n" << "long double: " << sizeof(long double) << "\n"
    << "char: " << sizeof(char) << "\n" << "bool: " << sizeof(bool) << "\n";

    while ( _getch()) {
        int a;
        cout << "введите целое число:";
        cin >> a;
        cout << "двоичное представление в памяти числа " << a << ":";
        int b = sizeof(a) * 8 - 1;
        unsigned int mask = 1 << b;
        if (a > 0){
            for (int i = 0; i <= b; i++) {
                if (i == 1 || i % 8 == 0)
                    putchar(' ');
                putchar(a & mask ? '1' : '0');
                mask = mask >> 1;
            }
        }
        if (a < 0){
            mask = mask >> 1;
            for (int i = 0; i <= b; i++) {
                if (i == 0)
                    putchar('1');
                for (i = 1; i <= b; i++) {
                    if (i == 1 || i % 8 == 0)
                        putchar(' ');
                    putchar((a*(-1)) & mask ? '1' : '0');
                    mask = mask >> 1;
                }
            }
        }

        cout << "\n\n";

        union {
            float f;
            int ia;
        };
        cout << "введите вещественное число:";
        cin >> f;
        cout << "двоичное представление в памяти числа типа float: ";
        //double f1 = double(f);
        int b1 = sizeof(f) * 8 - 1;
        int mask1 = 1 << b1;
        for (int i = 0; i <= b1; i++) {
            if (i == 1 || i == 9) {
                putchar(' ');
            };
            putchar(ia & mask1 ? '1' : '0');
            ia = ia << 1;
        }
        cout << "\n";

        union {
            double d;
            char mas[sizeof(d)];
        };
        cout << "введите вещественное число:";
        cin >> d;
        cout << "двоичное представление в памяти числа типа double: ";
        for (int i = sizeof(d) - 1; i >= 0; i--) {

            unsigned int byte = sizeof(char) * 8;
            unsigned int mask2 = 1 << (byte - 1);
            for (int k = 0; k < byte; k++) {
                putchar(mas[i] & mask2 ? '1' : '0');
                mask2 = mask2 >> 1;
                if (((i == 6) and (k == 3)) || ((i == 7) and (k == 0)))
                    putchar(' ');
            };
        };
        cout << "\n\n";

        cout << "нажмите enter чтобы продолжить" << endl;
    };
    return 0;
}
