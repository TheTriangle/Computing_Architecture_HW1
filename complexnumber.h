#ifndef __complexnumber__
#define __complexnumber__

//------------------------------------------------------------------------------
// complexnumber.h - содержит описание комплексного числа и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

// комплексное число
struct complexnumber {
    double real, imaginary;
};

// Ввод параметров комплексного числа из строки
void In(complexnumber &c, double real, double imaginary);

// Вывод параметров комплексного числа в строку
char* Out(complexnumber &c);

// Преобразование комплексного числа к действительному
double ConvertToReal(complexnumber &c);

#endif //__complexnumber__
