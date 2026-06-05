#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int>q;
  q.push(5);
  q.push(8);
  q.push(9);
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.back()<<endl;
  cout<<q.size()<<endl;

  return 0;
}