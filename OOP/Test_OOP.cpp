
#include <iostream>
#include "Course.h"
#include "Array.h"
#include "Single_Inheritance.h"
#include "Multiple_Inheritance.h"
#include "vitual_keyword.h"
#include "IntegerSet.h"
#include <vector>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

void Test_Course();
void Test_Array();
void Test_Single_Inheritance();
void Test_Multiple_Inheritance();
void Test_Virtual_Keyword();
void Test_IntegerSet();
void Test_explicitKeyword(GradeBook gb) {
	cout << "the course name: " << gb.getCourseName() << endl;
}
void Test_GradeBook() {

	using namespace std;// create two GradeBook objects
	GradeBook gradeBook1("CS101 Introduction to C++ Programming");
	GradeBook gradeBook2("CS102 Data Structures in C++");

	// display initial value of courseName for each GradeBook
	cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
		<< "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
		<< endl;
	string str = "eee";
	Test_explicitKeyword(string("eee"));
}

int main_Test_OOP() {
	//Test_Course();
	//Test_Array();
	//Test_Single_Inheritance();
	//Test_Multiple_Inheritance();
	//Test_Virtual_Keyword();
	//Test_IntegerSet();
	Test_GradeBook();


	return 0;
}
void Test_IntegerSet() {
	IntegerSet set1; int a[] = { 31, 5 , 10, 70 }; int b[] = { 1, 5 , 31, 80 };
	IntegerSet set2(a, 4); IntegerSet set3(set2); IntegerSet set4(b, 4);
	std::cout << "set3 = " << set3 << std::endl;
	std::cout << "set4 = " << set4 << std::endl;
	IntegerSet unionSet(set3 + set4);
	IntegerSet inter(set3 * set4);
	IntegerSet diff(set3 - set4);
	std::cout << "set3 U set4 = " << unionSet << std::endl;
	std::cout << "intersection of set3 and set4 = " << inter << std::endl;
	std::cout << "set3 - set4 = " << diff << std::endl;
}
void Test_Course() {
	Course java("Programming Principles", 101);
	Course DB("Data Base");
	Course zero;
	Course* CS316 = new Course("File Structures", 316);

	java.displayMessage();
	DB.displayMessage();
	zero.displayMessage();

	CS316->displayMessage();

	delete CS316;
}

void Test_Array() {
	Array a1;   //calling default constructor
	a1.printArray();
	Array a2(a1); //calling copy constructor
	a2.printArray();
	Array* a3 = new Array;

	cout << "============================================================== \n";
	cout << "Testing Equality Operator \n";
	if (a1 == a2)
		cout << "Two Array objects are equal. \n";
	else
		cout << "Two Array objects are not equal. \n";

	cout << "============================================================== \n";
	cout << "Testing Index Operator [ ]\n";
	for (int i = 0; i < a1.getSize(); i++)
	{
		a1[i] = i * 2;
	}
	cout << "Array Elements: [ ";
	for (int i = 0; i < a1.getSize(); ++i)
	{
		cout << a1[i] << ((i < a1.getSize() - 1) ? ", " : " ] \n");
	}
	/*cout << "============================================================== \n";
	cout << "Testing Stream Inerstion Operator << \n";
	cout << a1 ;
	*/
	cout << "============================================================== \n";
	cout << "Number of Array objects created = " << Array::getCount() << endl;
	cout << "============================================================== \n";
	delete a3;
}

void Test_Single_Inheritance() {
	Rectangle Rect(3, 4);

	/*Rect.setSide1(5);
	Rect.setSide2(7);*/

	// Print the area of the object.
	cout << "The rectangle area: " << Rect.getArea() << endl;
}

void Test_Multiple_Inheritance() {
	Rectangle2 Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	// Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;

	// Print the total cost of painting
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;
}

void Test_Virtual_Keyword() {

	vector<Animal*> creatures;

	creatures.push_back(new Bird("duck", true));
	creatures.push_back(new Bird("penguin", false));
	creatures.push_back(new Insect("spider", 8));
	creatures.push_back(new Insect("centipede", 44));

	// now iterate through the creatures and call their toString()

	for (int i = 0; i < creatures.size(); i++) {
		cout << creatures[i]->toString() << endl;
	}
}