#include <iostream>
#include "Person.h"

using namespace std;

int main(){
	Person person1;
	Person person2("Bob");
	cout << person1.toString() << endl;
	cout << person2.toString() << endl;
	return 0;
}
