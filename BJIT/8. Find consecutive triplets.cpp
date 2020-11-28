#include<iostream>
using namespace std;
#define  print(arr)  for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;
void merge(int arr[], int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    int temp[right];
    while(i<=mid and j<=right){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for(i=left; i<=right; i++) arr[i] = temp[i];
}
void mergeSort(int arr[], int left, int right){
    int mid;
    if(right>left){
        mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}
int findTriplets(int arr[], int n){
    mergeSort(arr, 0, n-1);
    print(arr);
    int triplets = 0;
    for(int i=0; i<n; i++){
        if(i<n-2 && arr[i+1]-arr[i]==1 && arr[i+2]-arr[i+1]==1) triplets++;
    }
    cout<<triplets<<endl;
}
int main(){
    int arr[ ] = {3, 2, 4, 5, 8, 9, 10, 13, 14, 15, 16, 3, 2, -1, -2, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTriplets(arr, n);
}
