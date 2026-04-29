#include<iostream>
using namespace std;

int main(){
    
    for(int i = 1; i <= 5; i++){   // repeat 5 times
        cout << "Loop " << i << ": ";
        
        for(int j = 1; j <= 10; j++){  // print 1 to 10
            cout << j << " ";
        }
        
        cout << endl;
    }

    return 0;
}