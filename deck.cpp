#include "number.h"

void PushFront(deck& d, number n) {
    d.length++;
    if (d.leftmost == nullptr) {
        d.leftmost = (node*)malloc(sizeof(node));
        d.leftmost->value = n;
        d.rightmost = d.leftmost;
        return;
    }

    d.rightmost->right = (node*)malloc(sizeof(node));
    d.rightmost->right->value = n;
    d.rightmost->right->left = d.rightmost;
    d.rightmost = d.rightmost->right;
}

void PushBack(deck& d, number n) {
    d.length++;
    if (d.leftmost == nullptr) {
        d.leftmost = (node*)malloc(sizeof(node));
        d.leftmost->value = n;
        d.rightmost = d.leftmost;
        return;
    }

    d.leftmost->left = (node*)malloc(sizeof(node));
    d.leftmost->left->value = n;
    d.leftmost->left->right = d.leftmost;
    d.leftmost = d.leftmost->left;
}

number PopFront(deck& d) {
    number ans = d.rightmost->value;
    if (d.length == 1) {
        free(d.rightmost);
        d.rightmost = nullptr;
        d.leftmost = nullptr;
        d.length--;
        return ans;
    }
    d.length--;
    node* newright = d.rightmost->left;
    free(d.rightmost);
    d.rightmost = newright;
    d.rightmost->right = nullptr;
    return ans;
}


number PopBack(deck& d) {
    number ans = d.leftmost->value;
    if (d.length == 1) {
        free(d.leftmost);
        d.rightmost = nullptr;
        d.leftmost = nullptr;
        d.length--;
        return ans;
    }
    d.length--;
    node* newleft = d.leftmost->right;
    free(d.leftmost);
    d.leftmost = newleft;
    d.leftmost->left = nullptr;
    return ans;
}

number Front(deck& d) {
    return d.rightmost->value;
}

number Back(deck& d) {
    return d.leftmost->value;
}

int Size(deck& d) {
    return d.length;
}

void Clear(deck& d) {
    if (d.length == 0)
        return;
    d.length = 0;
    while (d.leftmost != d.rightmost) {
        node* newleft = d.leftmost->right;
        free(d.leftmost);
        d.leftmost = newleft;
    }
    free(d.leftmost);
    d.leftmost = nullptr;
    d.rightmost = nullptr;
}

void SwapWithNext(node* n) {
    node* nextnode = n->right;
    //printf("UUUUU\n");

    if (n->left != nullptr)
        n->left->right = nextnode;
    //printf("AAAA\n");

    if (nextnode->right != nullptr)
        nextnode->right->left = n;
    nextnode->left = n->left;
    n->right = nextnode->right;

    n->left = nextnode;
    nextnode->right = n;
}

void print(deck& d) {
    node* runningnode = d.leftmost;
    if (runningnode == nullptr) return;
    while (runningnode != d.rightmost) {
        printf("%f ", ConvertToReal(runningnode->value));
        runningnode = runningnode->right;
    }
}

void BubbleSort(deck& d) {
    if (d.length <= 1)
        return;
    node* runningnode = d.leftmost;
    for (int i = 0; i < Size(d) - 1; i++) {
        for (int j = 0; j < Size(d) - i - 1; j++) {
            if (ConvertToReal(runningnode->value) > ConvertToReal(runningnode->right->value)) {
                if (runningnode == d.leftmost)
                    d.leftmost = runningnode->right;
                if (runningnode->right == d.rightmost)
                    d.rightmost = runningnode;
                SwapWithNext(runningnode);
            }
            else
                runningnode = runningnode->right;
        }
        runningnode = d.leftmost;
    }
}