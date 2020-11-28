/*
4 4
1 2 2
1 3 5
2 3 1
3 4 3
*/
#include<iostream>
using namespace std;
#define Max 1000

#define INF 1<<30 //2^30

int adj[Max][Max];
int dis[Max], cost[Max][Max];
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
void Bfs_Modified(int st, int en){
    Queue q;
    q.push(st);
    for(int i=1; i<=n; i++){
        dis[i] = INF;
    }
    dis[st] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<=n; v++){
            if(adj[u][v]==1){
                if(dis[u]+cost[u][v]<dis[v]){ //edge relaxation
                    q.push(v);
                    dis[v] = dis[u] + cost[u][v];
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
    int e, i, j, a, b, c;
    cin>>n>>e;
    for(i=0; i<e; i++){
        cin>>a>>b>>c;
        adj[a][b] = 1;
        cost[a][b] = c;
    }
    int source = 1, destination = n;
    Bfs_Modified(source, destination);

    for(int i=1; i<=n; i++){
        cout<<"Distance: form source to ith node:"<< dis[i]<<endl;
    }
    return 0;
}

