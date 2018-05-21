/*
 * writing text files.cpp
 *
 *  Created on: May 21, 2018
 *      Author: LuQiang
 */
#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1) // turn off padding, exactly fit, no padding
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main() {
//	ofstream outFile;
	fstream outFile;

	string outputFileName = "text.txt";
//	outFile.open(outputFileName);
//	outFile.open(outputFileName, ios::app); // append
	outFile.open(outputFileName, ios::out); // write


	if(outFile.is_open()) {
		outFile << "hello there" << endl;
		outFile << 123 << endl;

		outFile.close();
	}
	else {
		cout << "Could not create file: " << outputFileName << endl;
	}

	/// write binary file
	Person someone = {"Frodo", 220, 0.8};

	string fileName = "test.bin";
	ofstream outputFile;
	outputFile.open(fileName, ios::binary);

	if(outputFile.is_open()) {
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
		outputFile.close();
	}
	else {
		cout << "Could not creat file: " + fileName;
	}


	/// read binary file
	Person someoneElse = {};
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);

	if(inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
		inputFile.close();
	}
	else {
		cout << "Could not creat file: " + fileName;
	}

	cout << someoneElse.name <<", " << someoneElse.age << ", " << someoneElse.height << endl;

	return 0;
}



