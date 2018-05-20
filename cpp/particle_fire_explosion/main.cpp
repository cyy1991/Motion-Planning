/*
 * main.cpp
 *
 *  Created on: May 19, 2018
 *      Author: LuQiang
 */

#include "Screen.h"

using namespace std;
using namespace qiang;
int main(){
	// 0xFF123456;
	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char blue = 0x34;
	unsigned char green = 0x56;

	unsigned int color = alpha;
	color <<= 8;
	color += red;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += green;
	cout << setfill('0') << setw(8) << hex << color << endl;

	Screen screen;
	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}



	while(true) {
		// Update particles
		// Draw particles
		// Check for messages/events

		if(screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}


