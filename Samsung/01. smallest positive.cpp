#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int c = b;
    b = a;
    a = c;
}
int shiftNegToLeft(int arr[], int n){
    int j=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<" "<<j<<" "<<endl;
    return j;
}
/*if we find a positive integer, we mark it visited by making the value at its index position to negative.*/
/* ex: 2 3 1 here, arr[0]= 2 - 1 = 1, arr[1] = is positive; so we mark arr[1] = negative that implies 1+1= 2 is found */
int findMissingPositive(int arr[], int pos_size){
    for(int i=0; i<pos_size; i++){
        if( abs(arr[i])-1<pos_size && arr[abs(arr[i])-1]>0){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
    }
    for(int i=0; i<pos_size; i++){
        if(arr[i]>0) return i+1;
    }
    return pos_size+1;
}
int findMissing(int arr[], int n){
    int start = shiftNegToLeft(arr, n);
    int ans = findMissingPositive(arr+start, n-start);
    return ans;
}
int main(){
    int arr[100];
    int t, n, i, j;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0; i<n; i++) cin>>arr[i];
        cout<<findMissing(arr, n)<<endl;
    }
}

