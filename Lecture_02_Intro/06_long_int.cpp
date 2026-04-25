//use for lagre value which can't be store in  int size is 8byte
#include<iostream>
using namespace std;
int main(){
    long int a = 100000;
    cout<<a<<endl;
    cout<<sizeof(long int) ;
    return 0;
}

/*👉 long int = 8 bytes (64 bits) (Linux / Mac)
👉 long int = 4 bytes (Windows – most cases)*/