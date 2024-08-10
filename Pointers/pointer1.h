//
// Created by mem on 06-Aug-24.

// Prepocessor Directives
#include <iostream>
using namespace std;

void testpointer1(int, int &, int *);

//references & pointers
void pointer1() {
    int x = 100; //int variable
    int y = 2;
    int& r = x; // reference to int
    int* p;		// pointer to int
    p = &x; // & (ampersand): address operator; used to initialize a pointer.
    //x = 15;
    //r = y;
    //p = &y;
    x = 3;
    //&r = y;
    //r = y;
    //*p = y; // * (astrik): indirection operator; used only with pointers to
    //			   access the value which pointer refers to
    //p = &y;
//    cout << "x = " << x << endl;  //direct access
//    cout << "r = " << r << endl;  //direct access
    //We can consider reference as an alias for the variable, but they aren't equivalent.
//    cout << "*p = " << *p << endl; //indirect access
//    cout << "p = " << p << endl;
//    cout << "&r = " << &r << endl;
//    cout << "&x = " << &x << endl;


    // a pointer holds an address and by using the pointer, we can access both the address
    // and its content.
    // a reference is an address and by using the reference, we can only access its content.
    // With pointer, we can change the address, but with reference, we cannot.

    //TODO Task: Need to test how to pass references and pointers to a function ??
//    int a = 4; int b = 5; int c = 7;
//    int & bRef = b;
//    int * cPtr = &c;
//    cout << "before calling the function: " << endl;
//    printf("a = %d bRef = %d *cPtr = %d \n", a, bRef, *cPtr);
//    testpointer1(a, bRef, cPtr);
//    cout << "after calling the function: " << endl;
//    printf("a = %d bRef = %d *cPtr = %d", a, bRef, *cPtr);
}

void testpointer1(int a, int & b , int * c) {
    a = 10;
    b = 20;
    *c = 30;
}


