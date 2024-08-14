//
// Created by Mahmoud Esmat on 14-Aug-24.
//
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

void array_1(); // Initializing an array's elements to zeros and printing the array.
void array_2(); // Initializing an array in a declaration.
void array_3(); // Using range-based for to multiply an array's elements by 2.
void vector_1D();
void vector_2D();  //vector of vectors

void STL_main() {
    vector_1D();
}


// Initializing an array's elements to zeros and printing the array.
void array_1()
{
    array< int, 5 > n; // n is an array of 5 int values

    // initialize elements of array n to 0
    for ( size_t i = 0; i < n.size(); ++i )
        n[ i ] = 0; // set element at location i to 0

    cout << "Element" << setw( 13 ) << "Value" << endl;

    // output each array element's value
    for ( size_t j = 0; j < n.size(); ++j )
        cout << setw( 7 ) << j << setw( 13 ) << n[ j ] << endl;
} // end

// Initializing an array in a declaration.
void array_2()
{
    // use list initializer to initialize array n
    array< int, 5 > n = { 32, 27, 64, 18, 95 };
    //  If there are fewer initializers than elements in the array,
    // the remaining array elements are initialized to zero.

    cout << "Element" << setw( 13 ) << "Value" << endl;

    // output each array element's value
    for ( size_t i = 0; i < n.size(); ++i )
        cout << setw( 7 ) << i << setw( 13 ) << n[ i ] << endl;
} // end

// Using range-based for to multiply an array's elements by 2.
void array_3()
{
    array< int, 5 > items = { 1, 2, 3, 4, 5 };

    // display items before modification
    cout << "items before modification: ";
    for ( int item : items )
        cout << item << " ";

    // multiply the elements of items by 2
    for ( int &itemRef : items )
        itemRef *= 2;

    // display items after modification
    cout << "\nitems after modification: ";
    for ( int item : items )
        cout << item << " ";

    cout << endl;
} // end

void vector_1D() {
    // Creating a 1D vector with 5 elements
    std::vector<int> vec1D;
    vec1D.push_back(10);
    vec1D.push_back(20);
    vec1D.push_back(30);
    vec1D.push_back(40);
    vec1D.push_back(50);

    // Accessing and printing elements of the 1D vector
    std::cout << "1D Vector elements:" << std::endl;
    for (int i = 0; i < vec1D.size(); ++i) {
        std::cout << "Element at index " << i << " is " << vec1D[i] << std::endl;
    }

}
void vector_2D() {
    //vector of vectors of integers:
    vector<vector<int>> vector_2d;

    // To add a new vector, you can use the push_back() method:
    vector<int> myVector1 = {1, 2, 3};
    vector<int> myVector2 = {11, 22, 33};
    vector<int> myVector3 = {10, 20, 30};
    vector<int> myVector4 = {10, 20, 30};
    vector_2d.push_back(myVector1);
    vector_2d.push_back(myVector2);
    vector_2d.push_back(myVector3);
    vector_2d.push_back(myVector4);
    /*
    To access an element of the vector of vectors, you can use
    the[] operator twice, once to access the vector and again
    to access the element of that vector :
    */
    cout << "vector_2d[0][1] = " << vector_2d[0][1] << endl;

    // iterate through all the elements
    for (vector<int> &vec: vector_2d) {
        for (int &element: vec) {
            cout << element << ' ';
        }
        cout << endl;
    }
}
