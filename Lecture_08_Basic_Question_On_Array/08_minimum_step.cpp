//Given an arr[] containing N integers in one step, any element  of the array can either be increased or decreased by one. Find minimum step required such that the product of the array elements becomes 1
#include <iostream>
using namespace std;

class Solution
{
public:
  int makeProductOne(int arr[], int N){
    int count_zero = 0;
    int count_neg = 0;
    int step = 0;

    for(int i = 0; i < N; i++){
      if(arr[i] > 0){
        step += (arr[i] - 1);
      }
      else if(arr[i] < 0){
        step += (-1 - arr[i]);
        count_neg++;
      }
      else{
        count_zero++;
      }
    }

    if(count_neg % 2 != 0){
      if(count_zero > 0){
        step += 1;
        count_zero--;
      } else {
        step += 2;
      }
    }

    step += count_zero;

    return step;
  }
};

int main()
{
  Solution obj;

  int arr[] = {-1, -1, -1, 0, 1};
  int n = 5;

  cout << obj.makeProductOne(arr, n);

  return 0;
}