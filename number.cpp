//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенного числа
// и создания произвольного числа
//------------------------------------------------------------------------------

#include "number.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного числа
number* In(int k, double first, double second) {
    number *num;
    switch(k) {
        case 0:
            num = new number;
            num->k = number::COMPLEX;
            In(num->cn, first, second);
            return num;
        case 1:
            num = new number;
            num->k = number::FRACTION;
            In(num->fr, first, second);
            return num;
        case 2:
            num = new number;
            num->k = number::COORDINATES;
            In(num->cd, first, second);
            return num;
        default:
            return 0;
    }
}


//------------------------------------------------------------------------------
// Вывод параметров текущего числа в строку
char* Out(number &num) {
    //printf("s\n");
    switch(num.k) {
        case number::COMPLEX:
            return Out(num.cn);
            break;
        case number::FRACTION:
            return Out(num.fr);
            break;
        case number::COORDINATES:
            return Out(num.cd);
            break;
        default:
            char* ans = (char*)"Incorrect figure!\n";
            return ans;
    }
}

//------------------------------------------------------------------------------
// Приведение обобщенного числа к действительному
double ConvertToReal(number &num) {
    switch(num.k) {
        case number::COMPLEX:
            return ConvertToReal(num.cn);
            break;
        case number::FRACTION:
            return ConvertToReal(num.fr);
            break;
        case number::COORDINATES:
            return ConvertToReal(num.cd);
            break;
        default:
            return 0;
    }
}
