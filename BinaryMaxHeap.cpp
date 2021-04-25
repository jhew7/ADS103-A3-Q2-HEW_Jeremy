#include "BinaryMaxHeap.h"
#include <fstream> // File Reading/Writing

// Returns Left Child Node - " Arr[(2 * parent)+1]
int BinaryMaxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;

    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

// Returns Right Child Node - " Arr[(2 * parent)+2]
int BinaryMaxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;

    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

// Returns Parent Node - " Arr[(child-1)/2]
int BinaryMaxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;

    if (child == 0)
        return -1;
    else
        return parent;
}

// AFTER INSERTING
void BinaryMaxHeap::heapifyUp(int index)
{
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].inputHeapNum > heap[parentIndex(index)].inputHeapNum)
    {
        HeapedNums temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;

        heapifyUp(parentIndex(index));
    }
}

void BinaryMaxHeap::heapifyDown(int index)
{
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);

    int childIndex = childL;
    
    if (childL >= 0 && childR >= 0 && heap[childR].inputHeapNum > heap[childL].inputHeapNum)
    {
        childIndex = childR;
    }

    // IF childIndex is not the root node (0) and not -1
    // AND current node is bigger than child node
    if (childIndex > 0 && heap[index].inputHeapNum < heap[childIndex].inputHeapNum)
    {
        HeapedNums temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;

        heapifyDown(childIndex);
    }
}

// INSERTS always at the lowest next free node of the tree (keeps things balanced)
void BinaryMaxHeap::Insert(HeapedNums element)
{
    heap.push_back(element);
    heapifyUp(heap.size() - 1);     
}

void BinaryMaxHeap::DeleteMin()
{
    // cant delete if the heap is empty - return error message
    if (heap.size() == 0)
    {
        cout << "Heap Empty." << endl;
        return;
    }
    heap[0] = heap[heap.size() - 1];    
    // DELETE last element
    heap.pop_back();
    // then heapifyDown starting from ROOT (index 0)
    heapifyDown(0);
    cout << "Root Player deleted." << endl;
}

// get the ROOT player node from heap tree structure (the first element in the vector)
HeapedNums* BinaryMaxHeap::ExtractMin()
{
    // IF it's empty return nothing
    if (heap.size() == 0)
    {
        return NULL;
    }
    else
    {
        HeapedNums* p = &(heap.front());
        return p;
    }
}

// Shows in consol
void BinaryMaxHeap::showHeap()
{
    cout << "Max Heap: " << endl;
    for (HeapedNums p : heap)       
    {
        cout << p.inputHeapNum << " ";
    }
}

// Prints to text file
void BinaryMaxHeap::showHeapAndWrite()
{
    ofstream  writeFile;
    writeFile.open("output-a3q2.txt");
    writeFile << "Max Heap: " << endl;
    for (HeapedNums p : heap)       
    {
       writeFile << p.inputHeapNum << " ";
    }
        
    writeFile.close();
}

// NOTE: Kept this in here to show I tried to create the breadth traversed heap but coudln't get it to work
// Shows & Writes Traversed Heap
//void BinaryMaxHeap::showAndWriteTravHeap(HeapedNums* p)
//{
//    
//    // Create an empty queue for level order traversal
//    queue <HeapedNumsLevelNode> q;
//
//    // Enqueue Root and initialise height
//    q.push(HeapedNumsLevelNode(root, 0));
//
//    int previousOutputLevel = -1;
//
//    while (q.empty() == false)
//    {
//        // Opening file to get the amount of numbers so I can loop with them
//        ifstream readFile;
//        readFile.open("input-a3q2.txt");
//        int numberOfHeapNums;
//        int numbersToHeap;
//        readFile >> numberOfHeapNums;
//
//        // Write the results of avl1.show to txt file
//        ofstream  writeFile;
//        writeFile.open("output-a3q2.txt");
//
//        writeFile << "Heap Traversal: has now been writen to file." << endl;
//
//        // Loop through all numbers so they all print
//        for (HeapedNums p : heap)
//        {
//            for (int i = 0; i < numberOfHeapNums; i++)
//            {
//                // Print front of queue and remove it from queue
//                HeapedNumsLevelNode node = q.front();
//                while (node.level != previousOutputLevel)
//                {
//                    writeFile << endl;
//                    writeFile << node.level << " : ";
//                    previousOutputLevel = node.level;
//
//                }
//
//                writeFile << p.inputHeapNum << " ";
//                q.pop();
//                // Enqueue the LEFT Child
//                if (node.number->leftChild != NULL)
//                {
//                    q.push(HeapedNumsLevelNode(node.number->leftChild, node.level + 1));
//                }
//
//                // Enqueue the RIGHT Child
//                if (node.number->rightChild != NULL)
//                {
//                    q.push(HeapedNumsLevelNode(node.number->rightChild, node.level + 1));
//                }
//            }
//        }
//        writeFile.close();
//    }
//}

// HEAP SIZE
int BinaryMaxHeap::Size()
{
    return heap.size();   
}
