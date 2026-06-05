/* Question:
You only need to complete the function rev()
that takes a queue as parameter and returns
the reversed queue.

The printing is done automatically by the driver code.

Example:

Input:
Queue = 1 2 3 4 5

Output:
5 4 3 2 1
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;

    while(q.size())
    {
        s.push(q.front());   
        q.pop();
    }

    while(s.size())
    {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = rev(q);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}