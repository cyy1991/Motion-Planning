#include <iostream>
#include "Complex.h"

using namespace std;
using namespace qiang;

int main() {
	Complex c1(2, 3);
	Complex c2(c1);
	Complex c3 = c1;

	c2 = c1;
	c3 = c2;
	cout << c1 <<"   " << c3 << endl;

	cout << c1 + c3 + c2<< endl;

	Complex c4(4, 3);
	Complex c5 = c4 + 7;
	cout << c5 << endl;

	Complex c6(1, 7);
	cout << 3.2 + c6 << endl;
	cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;
	if(c1 != c2) {
		cout << " not equal" <<endl;
	}
	else{
		cout << " equal" << endl;
	}
	// complex number's conjugate number
	cout << *c1 << endl;
	cout << *c1 + *Complex(4, 3) << endl;

	return 0;
}
