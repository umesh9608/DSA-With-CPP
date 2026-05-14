/*Print this pattern
 1 1 1 1 1
 1 1 1 1 1 
 1 1 1 1 1 
 1 1 1 1 1*/

 //first approach make for loop and in every for loop prnt 1 four time
 //second approach we use loop and print many time 
 //in this we can repeat same loop we have to use loop for this we use nested loop here (loop ke ander loop)

 #include<iostream>
 using namespace std;
 int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<" 1 ";
        }
        cout<<endl;
    }
    return 0;
 }