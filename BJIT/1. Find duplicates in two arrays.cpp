#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

void findDuplicate(int arr1[], int arr2[], int n1, int n2){
    mergeSort(arr1, 0, n1-1);
    mergeSort(arr2, 0, n2-1);
    int i = 0, j = 0, cnt = 0;

    while(i<n1 and j<n2){
//        if(i<n1-1 && arr1[i]==arr1[i+1]) i++; REMOVE DUPLICATIONS IN ANSWER AS WELL
//        if(j<n2-1 && arr2[j]==arr2[j+1]) j++;
        if(arr1[i] == arr2[j]) { cout<<arr1[i]<<" "; cnt++; i++; j++; }
        else if(arr1[i]<arr2[j]) i++;
        else j++;
    }
    cout<<endl<<cnt<<endl;

}
int main(){
    int i, j, k;
    int arr1[] = {2, 3, 2, -4, 4, 5, 6};
    int arr2[] = {4, 5, 2, 2, 3, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2  = sizeof(arr2)/sizeof(arr2[0]);

    findDuplicate(arr1, arr2, n1, n2);
}

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
