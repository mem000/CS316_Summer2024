#pragma once
#include <iostream>

using namespace std;

class Animal { // Abstract Class since it includes at least a pure virtual function
protected:
    string name;
public:
    Animal(string name) {
        this->name = name;
    }
    //virtual string toString() { return "I am an animal"; }
    virtual string toString() = 0; // pure virtual function or (abstract function)
};

class Bird : public Animal {
private:
    bool canFly;
public:
    Bird(string name, bool canFly = true)
        : Animal(name)   // call the super class constructor with its parameter
    {
        this->canFly = canFly;
    }
    virtual string toString() { return "I am a bird, Name: " + name + "."; }
};


class Insect : public Animal {
private:
    int numberOfLegs;
public:
    Insect(string name, int numberOfLegs) : Animal(name) {
        this->numberOfLegs = numberOfLegs;
    }
    virtual string toString() { return "I am an insect, Name: " + name + "."; }
};

