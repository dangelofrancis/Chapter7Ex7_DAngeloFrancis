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

string GetFileName();
ifstream OpenFile(string);
void ReadFile(ifstream&, int[], int&);
void CloseFile(ifstream&);
void CompareNumbers(const int[], int);

int main() {
    const int ARRAY_SIZE = 15;
    int numbers[ARRAY_SIZE] = { 0 }; 
    int count = 0;

    string fileName = GetFileName();
    ifstream inputFile = OpenFile(fileName);

    if (inputFile) {
        ReadFile(inputFile, numbers, count);
        CloseFile(inputFile);
        CompareNumbers(numbers, count);
    }

    return 0;
}

string GetFileName() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    return fileName;
}

ifstream OpenFile(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile) {
        cout << "*ERROR* Unable to open file." << endl;
    }
    return inputFile;
}

void ReadFile(ifstream& inputFile, int numbers[], int& count) {
    const int ARRAY_SIZE = 15;
    count = 0; 

    while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
        count++;
    }
}

void CloseFile(ifstream& inputFile) {
    inputFile.close();
}

void CompareNumbers(const int numbers[], int count) {
    int highest = numbers[0];
    int lowest = numbers[0];
    int sum = 0;
    double average = 0.0;

    for (int i = 0; i < count; i++) {
        sum += numbers[i];

        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }

    average = static_cast<double>(sum) / count; 

    cout << endl;
    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Sum of numbers: " << sum << endl;
    cout << "Average of numbers: " << average << endl;
}
