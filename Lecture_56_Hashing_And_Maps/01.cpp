/*
FIRST REPEATING ELEMENT

Given an array of integers, find the first repeating element.
Return the element that appears more than once.

Example:
Input:
5
1 5 3 4 3

Output:
3

Explanation:
3 is the first element that repeats.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[n];
    unordered_map<int, bool> m;
    int ans = -1;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
    {
        if (m.count(A[i]))
        {
            ans = A[i];
            break;
        }
        else
        {
            m[A[i]] = true;
        }
    }

    cout << "First Repeating Element: " << ans;

    return 0;
}