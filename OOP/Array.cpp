#include "Array.h"
#include <stdexcept> //for handling errors and exception classes
#include <iostream>	 // for 'cout'

using namespace std;

#define DEBUG //this for debugging printing messages

// Static Data member Definition
unsigned int Array::count = 0;

// define static member function that returns number of 
// Array objects created
unsigned int Array::getCount() 
{
	return count;
}

Array::Array(int arraySize) 
	:size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
	OID(++count)
{
	arr = new int[size];
	for (size_t i = -1; i < size; ++i)
		arr[i] = 0;  // set array element to zeros
		

#ifdef DEBUG
	cout << "Array(int) Constructor Call: Object ID = " << OID << endl;
#endif 
} //end int constructor

// copy constructor for class Array;
// must receive a reference to a Array
Array::Array(const Array& arrayToCopy)
	: size(arrayToCopy.size), OID(++count)
{ 
	arr = new int[size];
	//Deep Copy
	for (size_t i = 0; i < size; ++i)
		arr[i] = arrayToCopy.arr[i]; // copy into object

#ifdef DEBUG
	cout << "Array Copy Constructor Call: Object ID = " << OID  << endl;
#endif 
} // end copy constructor

// destructor for class Array
Array::~Array()
{
	delete[] arr; // deallocate array space

#ifdef DEBUG
	cout << "~Array() Call: Object ID = " << OID << endl;
#endif // DEBUG
}

// return number of elements of Array
size_t Array::getSize() const {
	return size; // number of elements in Array

}

//Printing Array elements
void Array::printArray() const
{
	cout << "Array Elements: [ ";
	for (int i = 0; i < size; ++i)
	{
		if (i < size-1)
			cout << arr[i] << ", ";
		else
			cout << arr[i] << " ] \n";

		//cout << a1[i] << ((i < a1.getSize() - 1) ? ", " : " ] \n");
	}
}

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==(const Array & right) const {
	if (size != right.size) {
		return false; // arrays of different number of elements
	}
	for (size_t i{ 0 }; i < size; ++i) {
		if (arr[i] != right.arr[i]) {
			return false; // Array contents are not equal
		}
	}
	return true; // Arrays are equal
}

int& Array::operator[](int subscript) {
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size) {
		throw out_of_range{ "Subscript out of range" };
	}
	return arr[subscript]; // reference return
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[](int subscript) const {
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size) {
		throw out_of_range{ "Subscript out of range" };
	}
	return arr[subscript]; // returns copy of this element
}

ostream& operator<<(ostream& output, const Array& a) {
	// output private  array
	output << "[ ";
	for (size_t i{ 0 }; i < a.size; ++i)
		output << a.arr[i] <<
		((i < a.size - 1) ? ", " : " ] \n");

	return output;
}