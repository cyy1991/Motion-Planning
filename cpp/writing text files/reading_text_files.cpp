/*
 * reading_text_files.cpp
 *
 *  Created on: May 21, 2018
 *      Author: LuQiang
 */


#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string inFileName = "text.txt";
	ifstream inFile;

	inFile.open(inFileName);

	if(inFile.is_open()) {
		string line;
//		while(!inFile.eof()) {
		while(inFile) {
			getline(inFile, line);
			cout << line << endl;

		}

	}
	else {
		cout << "cannot open file: " << inFileName << endl;
	}

}

