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