// check number is even or odd
/* -> input number
   -> if number%2 is o, then eve
   -> if number % 2 is 1, the odd*/

   #include<iostream>
   using namespace std;
   int main(){
    int number;
    cout<<"Enter the number:";
    cin>>number;
    if(number % 2 == 0){
        cout<<number <<":is even";
    }else{
        cout<<number <<":is odd";
    }
    return 0;
   }