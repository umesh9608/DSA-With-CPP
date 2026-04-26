//Write a program to check given character is vowel or consonant
/*vowel: a e i o u
 if character is vowel then print vowel otherwise print consonant*/

 #include<iostream>
 using namespace std;
 int main(){
    char c;
    cout<<"Enta a character:";
    cin>>c;

    if(c=='a' || c== 'e' || c == 'i' || c == 'o' || c == 'u')
    cout<<"vowel";
    else
    cout<<"Consonant";

    return 0;
 }