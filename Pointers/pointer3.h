//
// Created by mem on 06-Aug-24.
//
#include <iostream>
using namespace std;
int x; // integer variable
int *p; // pointer to int
int *f(); //prototype of a function that returns a pointer to int
int (*g)(); // pointer to function that has no parameters and returns int
int w() { return 0; }

void pointer3() {
    g = w; // initialize g with w
    cout << g << endl;
}
