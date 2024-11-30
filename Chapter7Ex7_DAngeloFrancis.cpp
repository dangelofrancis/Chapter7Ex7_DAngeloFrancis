/*
TITLE: Chapter 7 Exercise 7 - Number Analysis
FILE NAME: Chapter7Ex7_DAngeloFrancis.cpp
PROGRAMMER: D'Angelo Francis
DATE: November 2024
REQUIREMENTS: 
Write a program that asks the user for a file name. 
Assume the file contains a series of numbers, each written on a separate line. 
The program should read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
*/

#include <iostream>
#include <fstream>
using namespace std;

void GetFileName();

int main() {
	GetFileName();
}
void GetFileName() {
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;

	ifstream inputFile(fileName);
	
	if (!inputFile) {
		cout << "*ERROR* Unable to open file.";
	}
}