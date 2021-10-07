#ifndef __coordinates__
#define __coordinates__

//------------------------------------------------------------------------------
// coordinates.h - �������� �������� ��������� ��������� � �� ����������
//------------------------------------------------------------------------------

using namespace std;

// ����������
struct coordinates {
    double angle, value;
};

// ���� ���������� ���������
void In(coordinates &c, double angle, double value);

// ����� ���������� ��������� � ������
char* Out(coordinates &c);

// �������������� ��������� � ��������������� �����
double ConvertToReal(coordinates &c);

#endif //__coordinates__
