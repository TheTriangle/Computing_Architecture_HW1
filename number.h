#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// number.h - �������� �������� ����������� �����,
//------------------------------------------------------------------------------

#include "fraction.h"
#include "coordinates.h"
#include "complexnumber.h"

//------------------------------------------------------------------------------
// ���������, ���������� ��� ��������� �����
struct number {
    // �������� ������ ��� ������� �� �����
    enum key {FRACTION, COORDINATES, COMPLEX};
    key k; // ����
    // ������������ ������������
    union { // ���������� ���������� ����������
        fraction fr;
        coordinates cd;
        complexnumber cn;
    };
};

// ���� ����������� �����
number *FromString(char* parsestr);

// ����� ����������� �����
char* ToString(number &s);

// ���������� ����������� ����� � ���������������
double ConvertToReal(number &n);

#include "number.cpp"
#endif

