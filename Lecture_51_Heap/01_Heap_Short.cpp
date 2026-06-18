/*
HEAP SORT

Given an array of size N, sort the array using Heap Sort.
Complete heapify() and buildHeap().

Example:
Input:
n = 5
arr[] = {4, 1, 3, 9, 7}

Output:
1 3 4 7 9

Explanation:
After applying heap sort, array becomes sorted.
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    void heapify(int arr[], int size, int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    obj.heapSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}