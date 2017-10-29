// blender2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	int projectLength;
	int clipLength;
	int cycle;
	string startNum = "001";
	string temp;
	string source;
	string loopString;

	cout << "Project Length: ";
	cin >> projectLength;
	cout << "Clip Length  (in seconds): ";
	cin >> clipLength;
	cycle = clipLength*30;
	clipLength = clipLength * 30;

	
	string line1 = "blender -b E:\\blenderfiles\\untitled.blend -x 1 -o //render_ -F AVIJPEG  -s ";
	source = line1;

	//line one
	line1.append(startNum);
	line1.append(" -e ");
	//convert cliplength to string
	temp = static_cast<ostringstream*>(&(ostringstream() << clipLength))->str();
	//append first line
	line1.append(temp);
	line1.append(" -S render_ -a");

	cout << line1 << endl;

	for (int i = 0; i < (projectLength / cycle) -2 ; i++)
	{
		loopString = source;
		//line one
		//convert clip length to string
		clipLength++;
		temp = static_cast<ostringstream*>(&(ostringstream() << clipLength))->str();
		loopString.append(temp);
		loopString.append(" -e ");
		clipLength = clipLength + 299;
		//convert cliplength to string
		temp = static_cast<ostringstream*>(&(ostringstream() << clipLength))->str();
		//append first line
		loopString.append(temp);
		loopString.append(" -S render_ -a");
		cout << loopString << endl;
	}
	loopString = source;




	//line one
	//convert clip length to string
	clipLength++;
	temp = static_cast<ostringstream*>(&(ostringstream() << clipLength))->str();
	loopString.append(temp);
	loopString.append(" -e ");
	//clipLength = clipLength + 299;
	//convert cliplength to string
	temp = static_cast<ostringstream*>(&(ostringstream() << projectLength))->str();
	//append first line
	loopString.append(temp);
	loopString.append(" -S render_ -a");
	cout << loopString << endl;

	



    return 0;
}

