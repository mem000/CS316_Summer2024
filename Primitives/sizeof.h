//
// Created by MahmoudEsmat on 06-Aug-24.
//
#include <iostream>

using namespace std;

int getSize(int *arr);

void sizeof_fun1() {
    cout << "sizeof(int):    " << sizeof(int) << " Bytes" << endl;
    cout << "sizeof(long):   " << sizeof(long) << " Bytes" << endl;
    cout << "sizeof(short):  " << sizeof(short) << " Bytes" << endl;
    cout << "sizeof(bool):   " << sizeof(bool) << " Bytes" << endl;
    cout << "sizeof(float):  " << sizeof(float) << " Bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " Bytes" << endl;
    cout << "==========================================================" << endl;
    int x = 5;
    char b = 'M';
    bool flag = true;
    double m = 14.5;

    cout << "sizeof(int var):    " << sizeof(x) << " Bytes" << endl;
    cout << "sizeof(char var):   " << sizeof(b) << " Bytes" << endl;
    cout << "sizeof(bool var):   " << sizeof(flag) << " Bytes" << endl;
    cout << "sizeof(double var): " << sizeof(m) << " Bytes" << endl;
    cout << "sizeof(3 + 3.5 ): " << sizeof(3 + 3.5) << " Bytes" << endl;
    cout << "sizeof(7 + 3): " << sizeof(7 + 3) << " Bytes" << endl;
    cout << "==========================================================" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "sizeof(arr) == " << sizeof(arr) << endl;
    cout << "getSize(arr) == " << getSize(arr) << endl;
    int arraySize = sizeof(arr) / sizeof(arr[0]); //getting array size using sizeof operator
    cout << "arraySize == " << arraySize << endl;
}
// The unary operator sizeof determines the size in bytes of a built-in array
// or of any other data type, variable or constant during program compilation.
//When applied to a built-in array’s name, the sizeof operator
// returns the total number of bytes in the built-in array as a value of type size_t.
//When applied to a pointer parameter in a function that receives a built-in array as an argument,
// the sizeof operator returns the size of the pointer in bytes—not the built-in array’s size.

int getSize(int *arr) {
    return sizeof(arr);
}