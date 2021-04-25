#pragma once
#include <iostream>
#include <string>

using namespace std;

class HeapedNums
{
public:
	int inputHeapNum;	
	
	HeapedNums* leftChild;
	HeapedNums* rightChild;

	HeapedNums(int inputHeapNum);
};

