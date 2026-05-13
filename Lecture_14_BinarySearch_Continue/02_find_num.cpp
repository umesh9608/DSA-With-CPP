// Find the smallest missing element from a sorted array
//0 1 2 6 9 11 15  missing = 3
#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int arr[n];
  cout<<"Enter value:";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int start=0,end=n-1, mid,index;
  while (start <= end){
    mid=(start+end)/2;

    if(mid<arr[mid]){
      index=mid;
      end=mid-1;
    }else{
      index=mid+1;
      start=mid+1;
    }
  }

  cout<<index;
}