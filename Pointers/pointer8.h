//
// Created by mem on 06-Aug-24.
//
#include <iostream>
using namespace std;

// Attempting to modify data through a
// nonconstant pointer to constant data.
void f( const int * ); // prototype

void pointer8()
{
    int y = 0;

    f( &y ); // f will attempt an illegal modification
}

// constant variable cannot be modified through xPtr
void f( const int *xPtr )
{
    //*xPtr = 100; // error: cannot modify a const object
} // end function f

// Attempting to modify a constant pointer to nonconstant data.
void r()
{
    int x, y;

    // ptr is a constant pointer to an integer that can
    // be modified through ptr, but ptr always points to the
    // same memory location.
    int * const ptr = &x; // const pointer must be initialized

    *ptr = 7; // allowed: *ptr is not const
    //ptr = &y; // error: ptr is const; cannot assign to it a new address
}

// Attempting to modify a constant pointer to constant data.
void test0()
{
    int x = 5, y;

    // ptr is a constant pointer to a constant integer.
    // ptr always points to the same location; the integer
    // at that location cannot be modified.
    const int *const ptr = &x;

    cout << *ptr << endl;

    //*ptr = 7; // error: *ptr is const; cannot assign new value
    //ptr = &y; // error: ptr is const; cannot assign new address
}
