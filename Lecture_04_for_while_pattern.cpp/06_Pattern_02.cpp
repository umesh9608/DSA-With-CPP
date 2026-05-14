/*
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/

#include <iostream>
using namespace std;
int main()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << col + 1 , cout<<" " ;
        }
        cout << "\n";
    }
    return 0;
}