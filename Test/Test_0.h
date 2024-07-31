// Prepocessor Directives
#include <iostream>
#include <string>

using namespace std;

//function prototypes (or function header / function declaration)
void fun0();  //Char && ASCII Value
void fun1();  //sizeof
void fun2();
void fun3(); // three ways of initializing variables
void fun6(); //references & pointers

int divide(int a, int b=2)
{
	int r;
	r = a / b;
	return (r);
}
int fun4()
{
	cout << divide(12);
	cout << endl;
	cout << divide(20, 4);
	return 0;
}
void fun5() {
	char question[] = "Please, enter your first name: ";
	char greeting[] = "Hello, ";
	char yourname[80];
	string mm;
	cout << question;
	cin >> yourname;
	//getline(cin, mm);
	cout << greeting << yourname << "!";
}

void print_Array_Size(int * arr);
void printArray(int * arr, int size);
void printArray2(int arr[], int size);
void printArray(int& arr, int size);
void passing_array_2_functions();

void test_static_local_var();
void static_local_var();

int main_Test_0() {
	//test_static_local_var();
	//passing_array_2_functions();
	fun3();
	return 0;
}

//references & pointers
void fun6() { 
	int x = 1; //int variable
	int y = 2;
	int& r = x; // reference to int
	int* p;		// pointer to int
	p = &x; // & (amperand): address operator; used to initialize a pointer.
	//x = 3;
	//&r = y;
	//r = y;
	//*p = y; // * (astrik): indirection operator); used only with pointers to
	        //			   access the value which pointer refers to
	//p = &y;
	cout << "x = " << x << endl;  //direct access
	cout << "r = " << r << endl;  //direct access
	//We can consider reference as an alias for the variable, but they aren�t equivalent.
	//cout << "p = " << p << endl;
	cout << "*p = " << *p << endl; //indirect access

	//TODO Task: Need to test how to pass references and pointers to a function ??
}

void fun0() {
	//--- Char && ASCII Value ---------------------
	char myChar = 'A';
	cout << "My character is " << myChar << endl;
	cout << "ASCII Value of " << myChar << " is " << int(myChar) << endl;
	int x = 99;
	cout << "Char corresponding to ASCII Value of " << x << " is " << char(x) << endl;
	char y = 105;
	cout << "y value " << y << endl;
	cout << "==========================================================" << endl;
	bool flag1 = true;
	bool flag2 = false;
	cout << flag1 << "\t" << flag2 << endl;
	cout << (flag1 + 10) << "\t" << (flag2 + 10) << endl;
	bool f1 = 5;
	bool f2 = -5;
	cout << f1 << "\t" << f2 << endl;
	cout << (f1 + 10) << "\t" << (f2 + 10) << endl;
	cout << "==========================================================" << endl;
}

void fun1() {
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
	cout << "sizeof(3 + 3.5 ): " << sizeof(3 + 3.5f) << " Bytes" << endl;
	cout << "sizeof(7 + 3): " << sizeof(7 + 3) << " Bytes" << endl;
	cout << "==========================================================" << endl;

	
}

void fun2() {
	int grade;
	cout << "Enter the student score out of 100 (integer Value): ";
	cin >> grade;
	cout << "==========================================================" << endl;
	//if statement
	if (grade >= 60) {
		cout << "The Student is passed" << endl;
	}
	cout << "==========================================================" << endl;
	//if-else statement
	if (grade % 2 == 0) {
		cout << grade << " is even.\n";
	}
	else {
		cout << grade << " is odd.\n";
	}
	cout << "==========================================================" << endl;
	//Multi-Way if-else
	cout << "The student grade is ";
	if (grade >= 85)
		cout << "\"Excellent\". \n";
	else if (grade >= 75)
		cout << "\"Very Good\". \n";
	else if (grade >= 65)
		cout << "\"Good\". \n";
	else if (grade >= 60)
		cout << "\"Passed\". \n";
	else
		cout << "\"Failed\". \n";
	cout << "==========================================================" << endl;
	// switch statement
	int day = 4;
	switch (day) {
	case 1:
		cout << "Saturday"; break;
	case 2:
		cout << "Sunday"; break;
	case 3:
		cout << "Monday"; break;
	case 4:
		cout << "Tuesday"; break;
	case 5:
		cout << "Wednesday"; break;
	case 6:
		cout << "Thursday"; break;
	case 7:
		cout << "Friday"; break;
	}
}

void fun3() { // three ways of initializing variables
	int a = 0;               // initial value: 5 //c-like initialization
	int b(1);                // initial value: 3 //constructor initialization             
	int c{ 2 };              // initial value: 2 //uniform initialization

	/*cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;*/

	a = (b = 4, b = b + 7, b + 2);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


void passing_array_2_functions() {
	int arr[] = { 1, 2, 3, 4, 5 };
	//print_Array_Size(arr);
	int size = sizeof(arr) / sizeof(arr[0]); //getting array size using sizeof operator
	//cout << "size == " << size << endl;
	printArray(arr, size);
	printArray2(arr, size);
	printArray(*arr, size);
}
void print_Array_Size(int* arr) {
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "size inside fun. = " << size << endl;
}
void printArray(int* arr, int size) {
	cout << "printArray(int* arr, int size)" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void printArray2(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void printArray(int & arr, int size) {
	cout << "printArray(int & arr, int size)" << endl;
	// here we convert the arr reference
	// to arr point to be able to use the index operator
	int* ptr = &arr;
	for (int i = 0; i < size; i++)
	{
		//cout << arr[i] << " "; // ERROR
		cout << ptr[i] << " "; 
	}
	cout << endl;
}

void static_local_var() {
	static int a = 0;
	int b = 0;
	cout << "Before modifying: a = " << a << " b = " << b << endl;
	a++;
	b++;
	cout << "After modifying: a = " << a << " b = " << b << endl;
}
void test_static_local_var() {
	cout << "After First Call to static_local_var() fun: " << endl;
	static_local_var();
	cout << "After Second Call to static_local_var() fun: " << endl;
	static_local_var();
	cout << "After Third Call to static_local_var() fun: " << endl;
	static_local_var();
}