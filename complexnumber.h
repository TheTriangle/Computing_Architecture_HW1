#ifndef __complexnumber__
#define __complexnumber__

//------------------------------------------------------------------------------
// complexnumber.h - �������� �������� ������������ ����� � ��� ����������
//------------------------------------------------------------------------------

using namespace std;

// ����������� �����
struct complexnumber {
    double real, imaginary;
};

// ���� ���������� ������������ ����� �� ������
void In(complexnumber &c, double real, double imaginary);

// ����� ���������� ������������ ����� � ������
char* Out(complexnumber &c);

// �������������� ������������ ����� � ���������������
double ConvertToReal(complexnumber &c);

#endif //__complexnumber__
