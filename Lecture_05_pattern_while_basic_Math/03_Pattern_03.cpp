/* This question is very difficult to print this pattern in one go

*             *
* *         * *
* * *     * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *

*/

#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    // upper part
    for (int row = 1; row <= n; row++)
    {
        // left stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        // spaces
        for (int col = 1; col <= 2 * (n - row); col++)
        {
            cout << "  ";
        }

        // right stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // lower part
    for (int row = n - 1; row >= 1; row--)
    {
        // left stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        // spaces
        for (int col = 1; col <= 2 * (n - row); col++)
        {
            cout << "  ";
        }

        // right stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}