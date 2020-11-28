#include <stdio.h>
#define Max 100

class Stack{
    int topId;
    int arr[Max];

    public:
    Stack(){ topId = -1; }
    void push(int x){ arr[++topId] = x; };
    int top(){return arr[topId]; };
    void pop(){ topId--; };
    bool empty(){ return topId<0; }
};

//void stack::push(int x){
//    arr[++topId] = x;
//}

class Queue{
    int frontId;
    int rearId;
    int arr[Max];
    public:
    Queue() { frontId = -1; rearId = 0; }
    void push(int x){ arr[++frontId] = x; }
    int  front(){return arr[rearId]; }
    void pop(){ rearId++; }
    bool empty(){ return rearId>frontId; }
};

int main()
{
    Stack s; //LIFO
    Queue q; //FIFO

    for(int i=10; i<=50; i+=10){
        s.push(i);
        q.push(i);
    }

    printf("Printing Stack:\n");
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }

    printf("\nPrinting Queue:\n");
    while(!q.empty()){
        printf("%d ", q.front());
        q.pop();
    }

}
