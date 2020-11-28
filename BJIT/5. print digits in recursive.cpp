#include<iostream>
using namespace std;
void printDigits(int n){
    if(n<0) { n = -1*n; cout<<"- "; }
    if(n/10>0){
        printDigits(n/10);
    }
    cout<<n%10<<" ";
}
int main(){
    int n;
    cin>>n;

    printDigits(n);
}
