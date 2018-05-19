#include <sstream>
#include "Person.h"

Person::Person(){
	name = "undefined";
	age = 0;
}
Person::Person(string newName){
	name = newName;
	age = 0;
}

string Person::toString(){
	stringstream ss;

	ss << "Name: " << name << "; age: " << age;
	return ss.str();
}
