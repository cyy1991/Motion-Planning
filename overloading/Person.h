#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person{
	private:
		string name;
		int age;
	public:
		Person();
		Person(string newName);
		string toString();
};


#endif /* PERSON_H_ */

