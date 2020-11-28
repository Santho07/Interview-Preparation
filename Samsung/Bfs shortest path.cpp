/*
Graph: Shafayet plaent bfs tutorial
10 14
1 2
1 3
1 4
2 6
6 10
4 7
3 7
3 8
8 7
6 10
7 9
8 5
10 9
10 5

*/

#include<iostream>
using namespace std;

#define Max 1000

int adj[Max][Max];
int vis[Max];
int parent[Max];
int n;

class Queue{
    int topId, frontId;
    int arr[Max];
public:
    Queue(){topId=-1, frontId = 0;}
    int push(int x){arr[++topId]=x;}
    int front(){ return arr[frontId]; }
    void pop(){ ++frontId;}
    bool empty(){return frontId>topId;}
};
void printpath(int src, int dst){

    if(dst!=src){
        printpath(src, parent[dst]);
    }
    cout<<dst<<" ";
}
void Bfs(int st, int en){
    Queue q;
    q.push(st);
    vis[st] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<=n; v++){
            if(adj[u][v]==1){
                if(vis[v]==0){
                    q.push(v);
                    vis[v]=1;
                    parent[v] = u;
                }
            }
        }
    }
    cout<<"Shortest path from "<<st<<" to "<<en<<" : "<<endl;
    printpath(st, en); cout<<endl;
    return;
}
int main(){
    int e, i, j, a, b;
    cin>>n>>e;
    for(i=0; i<e; i++){
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    Bfs(1, n);
}

