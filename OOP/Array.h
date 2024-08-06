
// Include Guard: prevent multiple inclusions of header
#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
	//Overloading stream insertion operator<<
	friend std::ostream& operator<<(std::ostream&, const Array&);
public:
	explicit Array(int = 10);		// default and int constructors
	Array(const Array&);			// Copy Constructor
	~Array();						// Destructor

	size_t getSize() const;			// return size

	void printArray() const;		// Printing Array elements

	// static member function
	static unsigned int getCount() ; // return # of objects created

	bool operator==(const Array&) const;	// Overlaoding equality operator

	//Overloading Subscript or array index operator []
	// subscript operator for non-const objects returns modifiable lvalue
	int& operator[](int);
	// subscript operator for const objects returns rvalue
	int operator[](int) const;

private:
	int* arr;						// pointer to first element of array
	size_t size;					// array size

	unsigned int OID;				// Object ID
	static unsigned int count;	// number of objects created // Static Data member Declaration
};

#endif