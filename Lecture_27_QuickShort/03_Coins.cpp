#include<iostream>
using namespace std;

/*
Question:
Given an array of integers and a target sum,
determine whether there exists a subset of the array
whose sum is equal to the given target sum.

Return:
1 -> If subset exists
0 -> If subset does not exist

Example:
Input:
arr[] = {2, 5, 1, 6, 7}
sum = 20

Output:
1

Explanation:
Subset {2, 5, 6, 7} gives sum = 20.
*/

bool sum_pos(int arr[], int size, int sum, int index,int total){
  if(index==size){
    if(sum==total)
    return 1;
    else
    return 0;
  }

  sum_pos(arr,size,sum,index+1,total);
  sum_pos(arr,size,sum,index+1,total+arr[index]) || sum_pos(arr,size,sum,index+1,total+arr[index]);
}

int main(){
  int arr[6]={2,5,1,6,7};
  int sum =20;
  int total =0;
  cout<<sum_pos(arr,6,sum,0,total);
  return 0;
}
//1.  kuch pal ki khushi or mahino br ki tension
//2. hr barr mood ke naam pe bahar khana (insaan hr khushi turant nhi kharidta)
//3 ase logo pr kharch jo apki kadar nhi kre
//faltu khardari
//bhanawo me kherch krna
//paisa sirf kagag nhi hota aha apki mahnet hai apka samay hai apki aajadi hai apki santi hai esliye jaruri chije pr kharch kro sikhne pr kharch kr maa baap pe kharch kro apne swath pr kharch kro palki sirf dikaye or aadto ke liye apni jindji ki kamai mat udawo

//hr gagha dildar bnana samjhadari nhi hoti kuch gajga pr kanjus bnana hi insaan ko fiture me majbut bnata hai