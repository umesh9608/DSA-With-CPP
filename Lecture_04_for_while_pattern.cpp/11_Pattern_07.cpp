/*
a a a a
b b b b
c c c c
d d d d

*/
#include <iostream>
using namespace std;

int main()
{
    // Outer loop controls the number of rows (0 to 3 = 4 rows)
    for (int row = 0; row < 4; row++)
    {
        // Sets the character for the current row ('a' for row 0, 'b' for row 1, etc.)
        char c = 'a' + row;

        // Inner loop controls the number of columns (prints 4 characters per row)
        for (int col = 0; col < 4; col++)
        {
            // Prints the character followed by a space
            cout << c << " ";
        }

        // Moves to the next line after finishing each row
        cout << endl;
    }
    
    return 0;
}
