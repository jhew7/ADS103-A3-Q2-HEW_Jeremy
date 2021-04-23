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
		heapedNumbers.Insert(NumbersToBeHeaped(temp));
	}

	readFile.close();

		
	heapedNumbers.showHeap();
	
	// Show Top of the Heap to Consol for checking
	NumbersToBeHeaped* topHeapedNumber = heapedNumbers.ExtractMin();
	
	if (topHeapedNumber != NULL)
	{
		cout << "\n\nTop of the Heap: " << topHeapedNumber->rank << " " << endl;
	}
	else
		cout << "Heap must be empty!!" << endl;


	system("pause");
}