#include<bits/stdc++.h>
using namespace std;
#define print(arr, n) for(int i=0; i<n; i++) { cout<<arr[i]<<" "; } cout<<endl;

int removeDuplicate(int arr[], int n){
    sort(arr, arr+n);
    print(arr, n);

    int temp[n];
    int j = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i]!=arr[i+1]) temp[j++] = arr[i];
    }
    temp[j++] = arr[n-1];
    for(int i=0; i<j; i++) arr[i] = temp[i];

    print(arr, j);

    return j;
}
int main(){
    int arr[] = {2, 4, 5, 6, 4, 2, 4, 5, 9};
    int len = sizeof(arr)/sizeof(arr[0]);

    print(arr, len);
    cout<<removeDuplicate(arr, len)<<endl;
}
