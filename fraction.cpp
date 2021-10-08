//------------------------------------------------------------------------------
// fraction.cpp - содержит процедуру ввода параметров
// для уже созданного числа-дроби
//------------------------------------------------------------------------------

#include "fraction.h"

//------------------------------------------------------------------------------
// Ввод параметров дроби
void In(fraction &f, double numenator, double denominator) {
    f.numenator = numenator;
    f.denominator = denominator;
}

//------------------------------------------------------------------------------
// Вывод параметров дроби в строку
char* Out(fraction &f) {
    char* outstr = (char*)malloc(sizeof(char)*100);
    snprintf(outstr, 99, "Fraction %f/%f - %f", f.numenator, f.denominator, ConvertToReal(f));
    return outstr;
}

//------------------------------------------------------------------------------
// Преобразование дроби к действительному числу
double ConvertToReal(fraction &f) {
    return f.numenator / f.denominator;
}
