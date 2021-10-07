//------------------------------------------------------------------------------
// number.cpp - �������� ��������� ��������� � ���������� ����������� �����
// � �������� ������������� �����
//------------------------------------------------------------------------------

#include "number.h"

//------------------------------------------------------------------------------
// ���� ���������� ����������� �����
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
// ����� ���������� �������� ����� � ������
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
// ���������� ����������� ����� � ���������������
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
