#ifndef __fraction__
#define __fraction__

//------------------------------------------------------------------------------
// fraction.h - �������� �������� ����� � �� ����������
//------------------------------------------------------------------------------

using namespace std;

// �����
struct fraction {
    double numenator, denominator;
};

// ���� ���������� �����
void In(fraction &c, double numenator, double denominator);

// ����� ���������� ����� � ������
char* Out(fraction &c);

// �������������� ����� � ��������������� �����
double ConvertToReal(fraction &c);

#endif //__fraction__
