//
// Created by mem on 06-Aug-24.
//

#ifndef CS316_SUMMER2024_POINTER4_H
#define CS316_SUMMER2024_POINTER4_H
// Pointer operators & and *.
#include <iostream>
using namespace std;

void pointer4()
{
    int a = 7; // assigned 7 to a
    int *aPtr = &a; // initialize aPtr with the address of int variable a

    cout << "The address of a is " << &a
         << "\nThe value of aPtr is " << aPtr << endl;
    cout << "\nThe value of a is " << a
         << "\nThe value of *aPtr is " << *aPtr << endl;
    cout << "\nShowing that * and & are inverses of "
         << "each other.\n&*aPtr = " << &*aPtr
         << "\n*&aPtr = " << *&aPtr << endl;

    //system("pause");
} // end main
#endif //CS316_SUMMER2024_POINTER4_H
