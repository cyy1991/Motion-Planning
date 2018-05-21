#include <iostream>
//#include <exception>
using namespace std;

class CanGoWrong {
public:
	CanGoWrong() {
		char *pMemory = new char[999999999999999999];
		delete [] pMemory;

	}
};

class MyException: public exception {
public:
	virtual const char* what() const throw() {
		return "Something bad happened!";
	}
};

class Test {
public:
	void goesWrong() {
		throw MyException();
	}
};

void goesWrong() {
	bool error1Detected = true;
	bool error2Detected = false;

	if(error1Detected) {
		throw bad_alloc();
	}

	if(error2Detected) {
		throw exception();
	}
}

int main() {

	try {
			goesWrong();
		}
		catch(exception &e) {
				cout << "catching exception: " << e.what() << endl;
		}
		catch(bad_alloc &e) {
			cout << "catching bad_alloc: " << e.what() << endl;
		}


	try {
		goesWrong();
	}
	// always put subclass exception before the base class.
	catch(bad_alloc &e) {
			cout << "catching bad_alloc: " << e.what() << endl;
		}

	catch(exception &e) {
		cout << "catching exception: " << e.what() << endl;
	}


	Test test;
	try {
		test.goesWrong();
	}
	catch(MyException &e) {
		cout << e.what() << endl;
	}

//	try {
//			CanGoWrong wrong;
//		}
//		catch(bad_alloc &e) {
//			cout << "Caught exception: " << e.what() << endl;
//		}
//
//		cout << "still running" << endl;

	return 0;
}
