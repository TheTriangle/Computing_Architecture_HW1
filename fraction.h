#ifndef __fraction__
#define __fraction__

//------------------------------------------------------------------------------
// fraction.h - содержит описание дроби и ее интерфейса
//------------------------------------------------------------------------------

using namespace std;

// дробь
struct fraction {
    double numenator, denominator;
};

// Ввод параметров дроби
void In(fraction &c, double numenator, double denominator);

// Вывод параметров дроби в строку
char* Out(fraction &c);

// Преобразование дроби к действительному числу
double ConvertToReal(fraction &c);

#endif //__fraction__
