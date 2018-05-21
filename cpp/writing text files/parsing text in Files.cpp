/*
 * parsing text in Files.cpp
 *
 *  Created on: May 21, 2018
 *      Author: LuQiang
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string filename = "text.txt";
	ifstream input;

	input.open(filename);

	if(!input.is_open()) {
		return 1;
	}

	while(input) {
		string line;

		getline(input, line, ':');
//		cout << line << endl;

		int population;
		input >> population;
		if(!input) {break;}

		input >> ws;

		cout << "'" <<line << "'" << "--'" << population << endl;
	}

	return 0;
}



