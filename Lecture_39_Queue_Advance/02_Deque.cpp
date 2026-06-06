#include<iostream>
#include<deque>
using namespace std;
int main(){
  deque<int>q;
  q.push_back(5);
  q.push_front(10);
  q.pop_back();
  cout<<q.front()<<endl;
  return 0;
}