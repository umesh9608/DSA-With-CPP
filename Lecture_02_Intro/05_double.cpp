//big decimal value use exe 994.08098908787 this can't store in float
#include<iostream>
using namespace std;
int main(){
    double db=90.098908989;
    cout<<db<<endl;
    cout<<sizeof(db); //8 byte
    return 0;
}