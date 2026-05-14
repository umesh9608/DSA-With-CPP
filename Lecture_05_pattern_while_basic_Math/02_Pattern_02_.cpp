/*
     *
    * *
   * * *
  * * * *

*/
#include <iostream>
using namespace std;

int main()
{
    int totalRow;
    cout << "Please Enter total no of row: ";
    cin >> totalRow;

    for (int row = 1; row <= totalRow; row++)
    {
        // space print
        for (int col = 1; col <= totalRow - row; col++)
        {
            cout << " ";
        }

        // star print
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}