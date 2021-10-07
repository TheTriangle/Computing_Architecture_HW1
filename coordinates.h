#ifndef __coordinates__
#define __coordinates__

//------------------------------------------------------------------------------
// coordinates.h - содержит описание структуры координат и ее интерфейса
//------------------------------------------------------------------------------

using namespace std;

// координаты
struct coordinates {
    double angle, value;
};

// ¬вод параметров координат
void In(coordinates &c, double angle, double value);

// ¬ывод параметров координат в строку
char* Out(coordinates &c);

// ѕреобразование координат к действительному числу
double ConvertToReal(coordinates &c);

#endif //__coordinates__
