/*
LONGEST COMMON SUBSTRING (Recursion)

Given two strings s1 and s2, find the length of the
Longest Common Substring.

A substring is a contiguous sequence of characters.

Example:
Input:
s1 = "ABCDGH"
s2 = "ACDGHR"

Output:
4

Explanation:
Longest Common Substring = "CDGH"
Length = 4
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Recursive function
int find(int n, int m, string &s1, string &s2, int &ans)
{
    if (n == 0 || m == 0)
        return 0;

    int len = 0;

    // Characters match
    if (s1[n - 1] == s2[m - 1])
    {
        len = 1 + find(n - 1, m - 1, s1, s2, ans);
        ans = max(ans, len);
    }

    // Check other possibilities
    find(n - 1, m, s1, s2, ans);
    find(n, m - 1, s1, s2, ans);

    return len;
}

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int ans = 0;
    find(n, m, s1, s2, ans);
    return ans;
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << "Length of Longest Common Substring: "
         << longestCommonSubstr(s1, s2, s1.length(), s2.length());

    return 0;
}