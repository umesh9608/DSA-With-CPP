/*
LONGEST COMMON SUBSTRING

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
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//-------------------- Top-Down (Memoization) --------------------//

int find(int n, int m, string &s1, string &s2, int &ans,
         vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int len = 0;

    if (s1[n - 1] == s2[m - 1])
    {
        len = 1 + find(n - 1, m - 1, s1, s2, ans, dp);
        ans = max(ans, len);
    }

    // Explore remaining states
    find(n - 1, m, s1, s2, ans, dp);
    find(n, m - 1, s1, s2, ans, dp);

    return dp[n][m] = len;
}

int longestCommonSubstrMemo(string s1, string s2, int n, int m)
{
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    find(n, m, s1, s2, ans, dp);

    return ans;
}

//-------------------- Bottom-Up (Tabulation) --------------------//

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

//-------------------- Driver Code --------------------//

int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << "Top-Down Answer : "
         << longestCommonSubstrMemo(s1, s2, s1.length(), s2.length()) << endl;

    cout << "Bottom-Up Answer: "
         << longestCommonSubstr(s1, s2, s1.length(), s2.length()) << endl;

    return 0;
}