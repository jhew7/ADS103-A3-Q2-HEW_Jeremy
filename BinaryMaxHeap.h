#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <queue>		// For Breadth Traversal
#include "HeapedNums.h"

using namespace std;

//HELPER CLASS
class HeapedNumsLevelNode
{
public:
	HeapedNums *number;
	int level;

	HeapedNumsLevelNode(HeapedNums* number, int level)
	{
		this->number = number;
		this->level = level;
	}
};

class BinaryMaxHeap
{
public:
	HeapedNums* root = NULL;
	vector<HeapedNums> heap;		
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyUp(int index);
	void heapifyDown(int index);
	
	void Insert(HeapedNums element);
	void DeleteMin();
	HeapedNums* ExtractMin();
	void showHeap();
	void showHeapAndWrite();
	//void showAndWriteTravHeap(HeapedNums* p);
	int Size();
};

