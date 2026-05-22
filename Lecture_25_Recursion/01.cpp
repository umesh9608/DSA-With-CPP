#include<iostream>
using namespace std;

void print_Num(int start, int end)
{
    if(start > end)
        return;

    cout << start << " ";

    print_Num(start + 1, end);
}

int main()
{
    print_Num(1, 10);

    return 0;
}