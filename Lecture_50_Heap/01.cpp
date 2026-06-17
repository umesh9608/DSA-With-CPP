/*
Question:
Write a C++ program to perform insertion and deletion in a Max Heap.

Operations:
1. Insert elements into the Max Heap.
2. Delete the root element (maximum element) from the heap.
3. Maintain Max Heap property after each operation.
4. Display the heap after deletion.

A Max Heap is a complete binary tree where every parent node
is greater than or equal to its child nodes.
*/

#include <iostream>
#include <vector>
using namespace std;

void insertHeap(vector<int>& maxHeap)
{
    int index = maxHeap.size() - 1;
    int parent;

    while (index > 0)
    {
        parent = (index - 1) / 2;

        if (maxHeap[parent] < maxHeap[index])
        {
            swap(maxHeap[parent], maxHeap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void Heapify(vector<int>& maxHeap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int size = maxHeap.size();

    if (left < size && maxHeap[left] > maxHeap[largest])
        largest = left;

    if (right < size && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != index)
    {
        swap(maxHeap[largest], maxHeap[index]);
        Heapify(maxHeap, largest);
    }
}

void deleteHeap(vector<int>& maxHeap)
{
    if (maxHeap.size() == 0)
    {
        cout << "Heap is empty\n";
        return;
    }

    maxHeap[0] = maxHeap[maxHeap.size() - 1];
    maxHeap.pop_back();

    if (!maxHeap.empty())
        Heapify(maxHeap, 0);
}

int main()
{
    vector<int> maxHeap;
    int n, element;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        maxHeap.push_back(element);
        insertHeap(maxHeap);
    }

    deleteHeap(maxHeap);
    deleteHeap(maxHeap);

    cout << "Max Heap: ";
    for (int i = 0; i < maxHeap.size(); i++)
    {
        cout << maxHeap[i] << " ";
    }

    return 0;
}