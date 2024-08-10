//
// Created by mem on 06-Aug-24.
//

#include <iostream>

using namespace std;

int cubeByValue(int); // prototype // Pass-by-value used to cube a variable’s value.
void cubeByReference(int *); // prototype // Pass-by-reference with a pointer argument used to cube a variable’s value.

void pointer7() {
    int number1 = 4;
    cout << "The original value of number is " << number1;
    number1 = cubeByValue(number1); // pass number by value to cubeByValue
    cout << "\nThe new value of number is " << number1 << endl;
    cout << "==================================\n";
    int number2 = 4;
    cout << "The original value of number is " << number2;
    cubeByReference(&number2); // pass number address to cubeByReference
    cout << "\nThe new value of number is " << number2 << endl;

}

// calculate and return cube of integer argument
int cubeByValue(int n) {
    return n * n * n; // cube local variable n and return result
} // end function cubeByValue

// calculate cube of *nPtr; modifies variable number in main
void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
} // end function cubeByReference