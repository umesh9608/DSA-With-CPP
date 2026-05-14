//wap to print fibonacci series like 0 1 1 2 3 5 8 13 21 34

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter any no:";
    cin>>n;

    if(n < 1) return 0; // Invalid input check
    
    int first = 0;
    int second = 1;

    // edge case: Pehle do numbers manually handle karein
    if(n >= 1) cout << first << " ";
    if(n >= 2) cout << second << " ";

    for(int i = 3; i <= n; i++){ // i=3 se n tak
        int next = first + second;
        cout << next << " "; // Har naya number print karein
        first = second;
        second = next;
    }

    return 0;
}
