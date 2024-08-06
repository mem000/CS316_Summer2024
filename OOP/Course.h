#pragma once
// prevent multiple inclusions of header
#ifndef COURSE_H
#define COURSE_H

#include <string> // class Course uses C++ standard string class

class Course { // Course class definition 
public:
	Course(std::string="NULL", int = 307); // constructor initialize courseName & CID
	void setCourseName(std::string); // sets the course name
	std::string getCourseName() const; // gets the course name
	void displayMessage() const; // displays a welcome message
private:
	std::string courseName; // course name 
	int CID; //Course ID
};

#endif