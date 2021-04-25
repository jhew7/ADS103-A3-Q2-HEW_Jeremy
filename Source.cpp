/******************************************************************************
*
*  ACADEMIC INTEGRITY DECLARATION
*
*   I, Jeremy Hew declare that except where I have referenced,
*  the work I am are submitting in this attachment is my own work. I
*  acknowledge and agree that the assessor of this assignment may,
*  for the purpose of authenticating this assignment, reproduce it
*  for the purpose of detecting plagiarism. I have read and am aware
*  of the Think Education Policy and Procedure viewable online at
*  http://www.think.edu.au/studying-at-think/policies-and-procedures/
*
******************************************************************************/

//// GIT HUB LINK: https://github.com/jhew7/ADS103-A3-Q2-HEW_Jeremy

#include <iostream>
#include <string>
#include <fstream>		// File Reading/Writing
#include "BinaryMaxHeap.h"

using namespace std;

void main()
{
	// Reading in numbers to work with
	ifstream readFile;
	readFile.open("input-a3q2.txt"); 

	int numberOfHeapNumbers;
	int numbersToHeap;

	readFile >> numberOfHeapNumbers;
	
	BinaryMaxHeap heapedNumbers;

	for (int i = 0; i < numberOfHeapNumbers; i++)
	{
		int temp;
		readFile >> temp;
		heapedNumbers.Insert(HeapedNums(temp));
	}

	readFile.close();

	// Showing in consol first	
	heapedNumbers.showHeap();
	
	// Show Top of the Heap to Consol for checking
	HeapedNums* topHeapedNumber = heapedNumbers.ExtractMin();
	
	if (topHeapedNumber != NULL)
	{
		cout << "\n\nTop of Max Heap: " << topHeapedNumber->inputHeapNum << " " << endl;
	}
	else
		cout << "Heap must be empty!!" << endl;

	// Writing to text file
	heapedNumbers.showHeapAndWrite();
	//heapedNumbers.showAndWriteTravHeap(heapedNumbers.root);

	system("pause");
}