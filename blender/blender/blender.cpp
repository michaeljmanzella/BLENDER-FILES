// blender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <string>


int main()
{
	//create video name
	string videoName;
	//file name
	string fileName;
	//create file name number
	int startFileNum = 1;
	//start location
	int startLocation = 0;
	//clip size
	int clipSize = 0;
	//create outfile
	int endSize = 0;
	//total
	int totalClipSize = 0;
	//interation
	int cycles;

	string line;
	string temp;
	
	string lineTwo;
	string lineTwoMiddle;
	string lineTwoThree;

	ofstream outFile;

	
	cout << "What is the file name: ";
	cin >> fileName;
	cout << "Number to start naming files: ";
	cin >> startFileNum;
	cout << "First Clip: ";
	cin >> startLocation;
	cout << "Clip Size: ";
	cin >> clipSize;
	endSize = clipSize;
	cout << "Total Clip Size: ";
	cin >> totalClipSize;
	cycles = totalClipSize / endSize;

	/*
	
	
	
	

	*/
	
	
	//blender -b E:\blender_files\	 
	string lineOne = "blender -b E:\\blender_files\\";
	lineOne.append(fileName);
	//blender -b E:\blender_files\untitled.blend
	string endLineone = " -x 1 \\";
	lineOne.append(endLineone);
	//blender -b E:\blender_files\untitled.blend -x 1 \

	//****************
	//add line one to front
	lineTwo = "-S ";
	//-S
	temp = static_cast<ostringstream*>(&(ostringstream() << startFileNum))->str();
	lineTwo.append(temp);
	//-S scene_name001
	lineTwoMiddle = " -o E:\\ -F AVI_JPEG -s ";
	lineTwo.append(lineTwoMiddle);
	//-S scene_name001 -o E:\ -F AVI_JPEG -s 
	
	temp = static_cast<ostringstream*>(&(ostringstream() << startLocation))->str();
	lineTwo.append(temp);
	//-S scene_name001 - o E : \ - F AVI_JPEG - s 1

	lineTwoThree = " -e ";
	lineTwo.append(lineTwoThree);
	//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e
	temp = static_cast<ostringstream*>(&(ostringstream() << endSize))->str();
	lineTwo.append(temp);
	//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e 250

	temp = " -a \\";
	lineTwo.append(temp);
	//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e 250 - a \
	
	//add to line one
	lineOne.append(lineTwo);
	cout << lineOne << endl;
	//cout << lineTwo << endl;
	
	for (int i = 0; i < cycles; i++)
	{
		//line three
		//start last end plus one
		//end new start plus 299
		lineTwo = "-S ";
		//-S
		startFileNum = startFileNum + 1;
		temp = static_cast<ostringstream*>(&(ostringstream() << startFileNum))->str();
		lineTwo.append(temp);
		//-S scene_name001
		lineTwoMiddle = " -o E:\\ -F AVI_JPEG -s ";
		lineTwo.append(lineTwoMiddle);
		//-S scene_name001 -o E:\ -F AVI_JPEG -s 


		startLocation = endSize + 1;
		temp = static_cast<ostringstream*>(&(ostringstream() << startLocation))->str();
		lineTwo.append(temp);
		//-S scene_name001 - o E : \ - F AVI_JPEG - s 1

		lineTwoThree = " -e ";
		lineTwo.append(lineTwoThree);
		//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e

		endSize = startLocation + 299;
		temp = static_cast<ostringstream*>(&(ostringstream() << endSize))->str();
		lineTwo.append(temp);
		//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e 250

		temp = " -a ";
		lineTwo.append(temp);
		//-S scene_name001 - o E : \ - F AVI_JPEG - s 1 - e 250 - a \

		cout << lineTwo << endl;
	}
	



	







	

	




    return 0;
}

