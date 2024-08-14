//
// Created by MahmoudEsmat on 06-Aug-24.
//
#include <iostream>
#include <string>
#include <cstring> // for The strlen() function
using namespace std;

void sizeof_basicTypes();

void sizeof_variables();

void sizeof_array();

int getSize(int *arr);

void sizeof_string();


void sizeof_test() {
    //sizeof_basicTypes();
    cout << "==========================================================" << endl;
    //sizeof_variables();
    cout << "==========================================================" << endl;
    //sizeof_array();
    /* The unary operator sizeof determines the size in bytes of a built-in array
     * or of any other data type, variable or constant during program compilation.
     * When applied to a built-in array’s name, the sizeof operator returns the total
     * number of bytes in the built-in array as a value of type size_t.
     * When applied to a pointer parameter in a function that receives a built-in
     * array as an argument,
     * the sizeof operator returns the size of the pointer in bytes—not the built-in
     * array’s size.
     */
    cout << "==========================================================" << endl;
    sizeof_string();
    cout << "==========================================================" << endl;
}

void sizeof_basicTypes() {
    cout << "sizeof(int):    " << sizeof(int) << " Bytes" << endl;
    cout << "sizeof(long):   " << sizeof(long) << " Bytes" << endl;
    cout << "sizeof(short):  " << sizeof(short) << " Bytes" << endl;
    cout << "sizeof(bool):   " << sizeof(bool) << " Bytes" << endl;
    cout << "sizeof(float):  " << sizeof(float) << " Bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " Bytes" << endl;
}

void sizeof_variables() {
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
}

void sizeof_array() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << "sizeof(arr) == " << sizeof(arr) << endl;
    cout << "getSize(arr) == " << getSize(arr) << endl;
    int arraySize = sizeof(arr) / sizeof(arr[0]); //getting array size using sizeof operator
    cout << "arraySize == " << arraySize << endl;
}

int getSize(int *arr) {
    return sizeof(arr);
}

void sizeof_string() {
    cout << "using sizeof with a string:" << endl;
    /* In C++, the sizeof operator is used to determine the size, in bytes,
     * of a data type or a variable. When used with a std::string, sizeof does
     * not return the length of the string or the number of characters it contains.
     * Instead, it returns the size of the std::string object itself, which typically
     * includes its internal data structure, such as pointers and other members used
     * to manage the string.
     * Here is an example to illustrate how sizeof works with std::string:
     */
    std::string myString1 = "I love you!"; // 11 charaters
    std::cout << "Size of std::string object: " << sizeof(myString1) << " bytes" << std::endl;
    std::cout << "Length of the string: " << myString1.length() << " characters" << std::endl;
    /* sizeof(myString) gives the size of the std::string object, which is typically
     * constant and independent of the actual content of the string. It is usually
     * the size of the internal data structure of std::string, which can vary depending
     * on the compiler and the standard library implementation.
     * myString.length() (or myString.size()) gives the number of characters in the string,
     * which is what you might be looking for if you're interested in the length of the content.
     * If you want to find the number of bytes used by the string content itself, you can use:
     */
    std::cout << "Size of string content: " << myString1.size() * sizeof(char) << " bytes" << std::endl;

    /* When dealing with a string defined as a character array in C++, the sizeof
     * operator can be used to determine the size of the array in bytes, including
     * the null terminator if present. Here's an example to illustrate this:
     */
    char myString2[] = "I love you!";   // 11 characters + null character = 12 bytes
    std::cout << "Size of char array: " << sizeof(myString2) << " bytes" << std::endl;
    std::cout << "Length of the string: " << strlen(myString2) << " characters" << std::endl;
    /* The strlen function returns the length of the string, which is the number
     * of characters before the null terminator.
     */
}

