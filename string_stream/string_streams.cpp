#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string name = "qiang";
	int age = 29;

	stringstream ss;

	ss << "Name is: " << name << " Age is: " << age;
	cout << ss.str() << endl;

}
