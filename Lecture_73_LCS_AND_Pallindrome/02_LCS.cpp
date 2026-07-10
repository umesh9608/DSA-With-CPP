/*
LONGEST COMMON SUBSEQUENCE (LCS) - Recursion

Given two strings s1 and s2, find the length of their
Longest Common Subsequence (LCS).

A subsequence is a sequence that appears in the same
relative order but not necessarily contiguous.

Example:
Input:
s1 = "ABCDGH"
s2 = "AEDFHR"

Output:
3

Explanation:
The Longest Common Subsequence is "ADH".
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Recursive function
int find(int n, int m, string s1, string s2)
{
    if (n == 0 || m == 0)
        return 0;

    // Characters match
    if (s1[n - 1] == s2[m - 1])
        return 1 + find(n - 1, m - 1, s1, s2);

    // Characters do not match
    return max(find(n - 1, m, s1, s2),
               find(n, m - 1, s1, s2));
}

int lcs(int n, int m, string s1, string s2)
{
    return find(n, m, s1, s2);
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout << "Length of LCS: " << lcs(s1.length(), s2.length(), s1, s2);

    return 0;
}