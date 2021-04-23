#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "NumbersToBeHeaped.h"

using namespace std;

class BinaryMaxHeap
{
public:
	vector<NumbersToBeHeaped> heap;		// vector is an array that can shrink and grow
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyUp(int index);
	void heapifyDown(int index);
	
	void Insert(NumbersToBeHeaped element);
	void DeleteMin();
	NumbersToBeHeaped* ExtractMin();
	void showHeap();
	int Size();
};

