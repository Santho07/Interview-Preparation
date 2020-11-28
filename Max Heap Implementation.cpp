/*
// Driver code
int main ()
{
    // Creates a max heap in STL
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

*/

#include<iostream>
using namespace std;
void swap(int *x, int *y);
const int Max_Size = 1000;

class maxHeap{
    int arr[Max_Size];
    int heap_size;
public:
    maxHeap(){
        heap_size = 0;
    }
    void push(int x);
    void pop();
    int top();
    bool empty();
    int parent(int i){return (i-1)/2;}
    void maxHeapify(int i);
};
void maxHeap::maxHeapify(int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int Max = i;
    if(left<heap_size && arr[left]>arr[i]) Max = left;
    if(right<heap_size && arr[right]>arr[Max]) Max = right;
    if(Max!= i){
        swap(&arr[i], &arr[Max]);
        maxHeapify(Max);
    }
}
void maxHeap::push(int x){
    heap_size++;
    int i = heap_size - 1;
    arr[i] = x;

    while(i!=0 && arr[i]>arr[parent(i)]){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}
void maxHeap::pop(){
    if(heap_size<=0) return;
    if(heap_size==1){
        heap_size--;
        return;
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    maxHeapify(0);
}
int maxHeap::top(){
    if(empty()==false) return arr[0];
    else cout<<"Heap is Empty"<<endl;
}
bool maxHeap::empty(){
    return heap_size<=0;
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    maxHeap pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
