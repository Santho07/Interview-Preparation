#include<iostream>
using namespace std;
int maxSum(int arr[], int n, int k){
    if(n<k) return 0;

    int res = 0;
    for(int i=0; i<k; i++) res+= arr[i];
    int curr_sum = res;
    for(int j=k; j<n; j++){
        curr_sum += arr[j] - arr[j-k];
        res = max(res, curr_sum);
    }
    return res;
}
int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr, n, k)<<endl;

    return 0;
}

