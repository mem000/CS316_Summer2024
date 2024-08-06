#pragma once
#include <iostream>

using namespace std;

class Shape { //Base Class (Super Class or Parent Class)
public:
	void print() const
	{
		//cout << "Shape::print Shape::side1 == " << side1 << ", Shape::side2 == " << side2 << "\n";
		cout << "Shape::print \n";
	}
	Shape(int s1=1, int s2=1) :side1(s1), side2(s2)
	{
		cout << "Shape::Shape(int=1, int=1) .. ";
		print();

	}
	void setSide1(int s1) {
		side1 = s1;
	}
	void setSide2(int s2) {
		side2 = s2;
	}

	~Shape() { cout << "Shape::~Shape() \n";  }

protected:
	int side1;
	int side2;
};

// Derived class (Subclass or child class)
class Rectangle : public Shape {
public:
	void print() const
	{
		//cout << "Rectangle::print Rectangle::side1 == " << side1 << ", Rectangle::side2 == " << side2 << "\n";
		cout << "Rectangle::print \n";
		//Shape::print();
	}
	Rectangle(int s1, int s2)
		//:Shape(s1, s2)    //Calling Base Class constructor
	{
		//Shape(s1, s2);
		cout << "Rectangle::Rectangle(int=2, int=2) .. ";
		print();

	}

	~Rectangle() { cout << "Rectangle::~Rectangle() \n"; }

	int getArea() {
		return (side1 * side2);
	}
};