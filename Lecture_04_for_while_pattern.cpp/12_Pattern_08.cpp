/*a
a b
a b c
a b c d
*/

#include <iostream>
using namespace std;

int main()
{
    // Outer loop rows control karta hai (0 to 3)
    for (int row = 0; row < 4; row++)
    {
        // Inner loop utni hi baar chalega jitna row number hai (Triangle shape)
        for (int col = 0; col <= row; col++)
        {
            // 'a' mein column number add karne se sequence banta hai (a, b, c, d)
            char c = 'a' + col; 
            cout << c << " ";
        }
        // Har row ke baad nayi line
        cout << endl;
    }
    return 0;
}
