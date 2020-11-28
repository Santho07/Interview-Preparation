/*
// Driver code
int main ()
{
    // Creates a min heap in STL
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from min heap
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
const int MAX = 1000;

class minHeap{
    int arr[MAX];
    int heap_size;
public:
    minHeap(){
        heap_size = 0;
    }
    void push(int x);
    void pop();
    int top();
    bool empty();
    int parent(int i){return (i-1)/2;}
    void minHeapify(int i);
};
void minHeap::minHeapify(int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int Min = i;
    if(left<heap_size && arr[left]<arr[i]) Min = left;
    if(right<heap_size && arr[right]< arr[Min]) Min = right;
    if(Min != i){
        swap(&arr[i], &arr[Min]);
        minHeapify(Min);
    }
}
void minHeap::push(int x){
    heap_size++;
    int i = heap_size - 1;
    arr[i] = x;

    while(i!=0 && arr[parent(i)]>arr[i]){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}
void minHeap::pop(){
    if(heap_size<=0) return;
    if(heap_size==1){
        heap_size--;
        return;
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    minHeapify(0);
}
int minHeap::top(){
    if(empty()==false) return arr[0];
    else cout<<"Heap is Empty"<<endl;
}
bool minHeap::empty(){
    return heap_size<=0;
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    minHeap pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}

