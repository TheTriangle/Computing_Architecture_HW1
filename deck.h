#include "node.h"

struct deck {
    node* rightmost = nullptr;
    node* leftmost = nullptr;

    int length = 0;
};


void PushFront(deck& d, number n);

void PushBack(deck& d, number n);

number PopFront(deck& d);

number PopBack(deck& d);

number Front(deck& d);

number Back(deck& d);

int Size(deck& d);

void Clear(deck& d);

void BubbleSort(deck& d);

void Swap(node* n);