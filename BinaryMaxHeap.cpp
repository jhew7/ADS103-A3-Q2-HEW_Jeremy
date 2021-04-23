#include "BinaryMaxHeap.h"

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

// AFTER INSERTING - we heapifyup from where that new inserted player ended up
// compares current node with parent and swaps the smaller to the top
// this is a recursive function, so it will call itself (heapifyup) on the next higher level where we swapped the value
void BinaryMaxHeap::heapifyUp(int index)
{
    // IF index is not the root (top of the tree or NULL)
    // AND parent index within heap bounds is not negative ( >= 0 )
    // AND current nodes rank is less than parent nodes rank
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].rank > heap[parentIndex(index)].rank)
    {
        // IF SO, swap values between current node and parent
        NumbersToBeHeaped temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        // since we swapped, now we can run heapifyup again recursively on the parent from here
        heapifyUp(parentIndex(index));
        // as soon as we call heapifyUp and there is no value then the loop will stop
    }
}

// DOWN is less efficient to UP
// we have to compare both children first before moving down
// usually called when destroyed root of tree
// also recursive, keeps calling itself as it swaps down the tree
void BinaryMaxHeap::heapifyDown(int index)
{
    // get left and right child indexes (index position in the array)
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);
    // child variable representing the path we'll compare down
    int childIndex = childL;
    
    // IF childL is not -1
    // AND childR is not -1
    // AND childR.rank is less than childL.rank 
    if (childL >= 0 && childR >= 0 && heap[childR].rank > heap[childL].rank)
    {
        // make right child index the focus of left
        childIndex = childR;
    }

    // IF childIndex is not the root node (0) and not -1
    // AND current node is bigger than child node
    if (childIndex > 0 && heap[index].rank < heap[childIndex].rank)
    {
        // then we swap current with child so we have smaller nodes to the top
        NumbersToBeHeaped temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;
        // recurse further down - keep calling until bottom of tree
        heapifyDown(childIndex);
    }
}

// INSERTS always at the lowest next free node of the tree (keeps things balanced)
void BinaryMaxHeap::Insert(NumbersToBeHeaped element)
{
    heap.push_back(element);
    heapifyUp(heap.size() - 1);     // starts at the bottom (size of the array - 1)
}

void BinaryMaxHeap::DeleteMin()
{
    // cant delete if the heap is empty - return error message
    if (heap.size() == 0)
    {
        cout << "Heap Empty." << endl;
        return;
    }
    // COPY value in LAST element into ROOT
    heap[0] = heap[heap.size() - 1];    // OR - heap.at(heap.size()-1)
    // DELETE last element
    heap.pop_back();
    // then heapifyDown starting from ROOT (index 0)
    heapifyDown(0);
    cout << "Root Player deleted." << endl;
}

// get the ROOT player node from heap tree structure (the first element in the vector)
NumbersToBeHeaped* BinaryMaxHeap::ExtractMin()
{
    // IF it's empty return nothing
    if (heap.size() == 0)
    {
        return NULL;
    }
    else
    {
        NumbersToBeHeaped* p = &(heap.front());
        return p;
        // OR
        // return &(heap.front());     // & for getting the memory address of (heap.front())
    }
}

void BinaryMaxHeap::showHeap()
{
    cout << "Heap: " << endl;
    for (NumbersToBeHeaped p : heap)       // for each (:) player in the heap
    {
        cout << p.rank << " ";
    }
}

// size of the array (heap)
int BinaryMaxHeap::Size()
{
    return heap.size();   
}
