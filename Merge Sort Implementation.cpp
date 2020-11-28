#include <iostream>
using namespace std;

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
int main(){
    int arr[] = {3, 2, 1, 4, 4, 5, 7, -1, -3, -5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, arr_size-1);
    for(int i=0; i<arr_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
