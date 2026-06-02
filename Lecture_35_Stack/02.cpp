#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int>s;
  s.push(4);
  s.push(14);
  s.push(41);
  s.push(400);
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.empty()<<endl; //yes then show 1 no then show 0
  return 0;
}