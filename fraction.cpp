//------------------------------------------------------------------------------
// fraction.cpp - �������� ��������� ����� ����������
// ��� ��� ���������� �����-�����
//------------------------------------------------------------------------------

#include "fraction.h"

//------------------------------------------------------------------------------
// ���� ���������� �����
void In(fraction &f, double numenator, double denominator) {
    f.numenator = numenator;
    f.denominator = denominator;
}

//------------------------------------------------------------------------------
// ����� ���������� ����� � ������
char* Out(fraction &f) {
    char* outstr = (char*)malloc(sizeof(char)*100);
    snprintf(outstr, 99, "Fraction %f/%f - %f", f.numenator, f.denominator, ConvertToReal(f));
    return outstr;
}

//------------------------------------------------------------------------------
// �������������� ����� � ��������������� �����
double ConvertToReal(fraction &f) {
    return f.numenator / f.denominator;
}
