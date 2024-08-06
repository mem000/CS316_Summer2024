#pragma once
#include <iostream>
using namespace std;

class Shape2 { // Base class Shape
public:
	Shape2() {
		cout << "Shape2 Default Constructor" << endl;
	}
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	~Shape2() { cout << "Shape2 Destructor Call \n"; }

protected:
	int width;
	int height;
};

class PaintCost { // Base class PaintCost
public:
	PaintCost() {
		cout << "PaintCost Default Constructor" << endl;
	}
	int getCost(int area) {
		return area * 70;
	}
	~PaintCost() { cout << "PaintCost Destructor Call \n"; }
};

// Derived class
class Rectangle2 : public Shape2, public PaintCost {
public:
	Rectangle2() {
		cout << "Rectangle2 Default Constructor" << endl;
	}
	int getArea() {
		return (width * height);
	}
	~Rectangle2() { cout << "Rectangle2 Destructor Call \n"; }
};