//
// Created by mem on 06-Aug-24.
//


#include <iostream>

using namespace std;

void increase(void *data, int psize) {
    if (psize == sizeof(char)) {
        char *pchar;
        pchar = (char *) data;
        ++(*pchar);
    }
    else if (psize == sizeof(int)) {
        int *pint;
        pint = (int *) data;
        ++(*pint);
    }
}

int pointer6() {
    char a = 'x';
    int b = 1602;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout << a << ", " << b << endl;
    return 0;
}

