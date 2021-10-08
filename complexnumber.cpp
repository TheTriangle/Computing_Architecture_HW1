//------------------------------------------------------------------------------
// complexnumber_In.cpp - �������� ��������� ����� ����������
// ��� ��� ���������� ������������ �����
//------------------------------------------------------------------------------

#include "complexnumber.h"
#include "math.h"

//------------------------------------------------------------------------------
// ���� ���������� ������������ ����� �� �����
void In(complexnumber &c, double real, double imaginary) {
    c.real = real;
    c.imaginary = imaginary;
}

//------------------------------------------------------------------------------
// ����� ���������� ������������ ����� � ������
char* Out(complexnumber &c) {
    char* outstr = (char*)malloc(sizeof(char)*100);
    snprintf(outstr, 99, "Complex number (%f; %f) - %f", c.real, c.imaginary, ConvertToReal(c));
    return outstr;
}

//------------------------------------------------------------------------------
// �������������� ������������ ����� � ���������������
double ConvertToReal(complexnumber &c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}
