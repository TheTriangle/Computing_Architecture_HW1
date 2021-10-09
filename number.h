#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающего числа,
//------------------------------------------------------------------------------

#include "fraction.h"
#include "coordinates.h"
#include "complexnumber.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся числа
struct number {
    // значения ключей для каждого из чисел
    enum key {FRACTION, COORDINATES, COMPLEX};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        fraction fr;
        coordinates cd;
        complexnumber cn;
    };
};

// Парс обобщенного числа
number *FromString(char* parsestr);

// Вывод обобщенного числа
char* ToString(number &s);

// Приведение обобщенного числа к действительному
double ConvertToReal(number &n);

#include "number.cpp"
#endif

