/*Given an array of penalties fine[], an array of car number car[], and also the date. The task is to find the total fine whihc weill be collected on the given date. Fine is colldected from odd-number cars on even dates and voice versa.*/
// #include<iostream>
// using namespace std;

// int main(){
//   int n = 4;
//   int date = 12;

//   int car[]  = {2375, 7682, 2325, 2352};
//   int fine[] = {500, 200, 300, 400};

//   int collection = 0;

//   if(date % 2 == 0){ // even date → odd car fined
//     for(int i = 0; i < n; i++){
//       if(car[i] % 2 == 1){
//         collection += fine[i];
//       }
//     }
//   }
//   else{ // odd date → even car fined
//     for(int i = 0; i < n; i++){
//       if(car[i] % 2 == 0){
//         collection += fine[i];
//       }
//     }
//   }

//   cout << "Total Fine: " << collection;

//   return 0;
// }

//----------------type 2------------
#include<iostream>
using namespace std;

int main(){
  int n = 4;
  int date = 12;

  int car[]  = {2375, 7682, 2325, 2352};
  int fine[] = {500, 200, 300, 400};

  int collection = 0;

  for(int i=0; i<n; i++){
    if(date%2 != car[i]%2){
      collection = collection + fine[i];
    }
  }

  cout << "Total Fine: " << collection;

  return 0;
}