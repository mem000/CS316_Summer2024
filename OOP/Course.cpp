#include <iostream> //system header file
#include "Course.h" //user defined header file
using namespace std;

Course::Course(string name, int id)
    : courseName(name), CID(id) // member initializer to initialize courseName 
{
    // empty body
}
void Course::setCourseName(string name)
{
    courseName = name; 
} 
string Course::getCourseName() const
{
    return courseName; 
} 
void Course::displayMessage() const
{
    cout << "Welcome to the Course: " << courseName
        << " ID: "<< this->CID << endl; 
    //this: contant pointer refers to the current object...
} 