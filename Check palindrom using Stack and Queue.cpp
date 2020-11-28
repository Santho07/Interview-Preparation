#include <stdio.h>
#define Max 100

class stack{
    int topId;
    char arr[Max];

    public:
    stack(){ topId = -1; }
    void push(int x){ arr[++topId] = x; };
    int top(){return arr[topId]; };
    void pop(){ topId--; };
    bool empty(){ return topId<0; }
};

class queue{
    int topId;
    int frontId;
    char arr[Max];
    public:
    queue() { topId = -1; frontId = 0; }
    void push(int x){ arr[++topId] = x; }
    int  front(){return arr[frontId]; }
    void pop(){ frontId++; }
    bool empty(){ return frontId>topId; }
};

void checkPalindrome(char str[]){
    class stack s; //LIFO
    class queue q; //FIFO
    int len = 0;
    while(str[len]!='\0') len++;

    for(int i=0; i<len; i++){
        s.push(str[i]);
        q.push(str[i]);
    }
    bool flag = true;

    while(!s.empty()){
        if(s.top()!=q.front()) flag = false;
        s.pop(); q.pop();
    }
    if(flag) printf("Yes\n");
    else printf("No\n");

    return;
}


int main()
{
    char s[100];
    gets(s);
    checkPalindrome(s);
}

