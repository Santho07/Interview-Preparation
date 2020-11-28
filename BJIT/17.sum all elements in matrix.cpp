#include<iostream>
using namespace std;
const int MaxN = 100;

int sumOfMatrix(int p, int sum, int n,  int arr[][MaxN]){
    if(n==p) {
        return sum;
    }
    for(int i=0; i<n; i++){
        sum += arr[p][i];
    }
    sumOfMatrix(p+1, sum, n, arr);
}
int main(){
    int arr[][MaxN] ={{1,2}, {2,3}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sumOfMatrix(0, 0, n, arr)<<endl;
}

