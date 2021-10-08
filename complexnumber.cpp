//------------------------------------------------------------------------------
// complexnumber_In.cpp - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "complexnumber.h"
#include "math.h"

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
void In(complexnumber &c, double real, double imaginary) {
    c.real = real;
    c.imaginary = imaginary;
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в строку
char* Out(complexnumber &c) {
    char* outstr = (char*)malloc(sizeof(char)*100);
    snprintf(outstr, 99, "Complex number (%f; %f) - %f", c.real, c.imaginary, ConvertToReal(c));
    return outstr;
}

//------------------------------------------------------------------------------
// Преобразование комплексного числа к действительному
double ConvertToReal(complexnumber &c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}
