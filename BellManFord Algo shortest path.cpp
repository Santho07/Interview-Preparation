/*
3 3
0 1 3
1 2 4
2 0 -10
*/
#include<iostream>
using namespace std;
#define Max 1000
#define INF 1<<30 //2^30

int graph[Max][3];

int parent[Max];
int n, e;

void printpath(int src, int dst){

    if(dst!=src){
        printpath(src, parent[dst]);
    }
    cout<<dst<<" ";
}
void BellManFord(int st){
    int dis[n+10];
    for(int i=0; i<n; i++){
        dis[i] = INF;
    }
    dis[st] = 0;
    for(int i=1; i<=n-1; i++){ // update n-1 times all edge
        for(int j=0; j<e; j++){ //traverse all edge and update dis.
            int u = graph[j][0]; int v = graph[j][1];
            int cost = graph[j][2];
            if(dis[u]+cost<dis[v]){
               dis[v] = dis[u]+cost;
               parent[v] = u;
            }
        }
    }
    for(int j=0; j<e; j++){ //if the edge can still be updated there is negative cycle
        int u = graph[j][0];
        int v = graph[j][1];
        int cost = graph[j][2];
        cout<<dis[u]<<"+"<<cost<<" ? dis[v] = "<<dis[v]<<endl;
        if(dis[u]+cost<dis[v]){
           cout<<"Negative Cycle Exists"<<endl;
           break;
        }
    }
    cout<<"Shortest path from "<<st<<" to "<<n<<" : "<<endl;
    printpath(st, n); cout<<endl;
    return;
}
int main(){
    int i, j;
    cin>>n>>e;
    for(i=0; i<e; i++){
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    }
    cout<<graph[n-1][0]<<graph[n-1][1]<<graph[n-1][2];
    BellManFord(0);
}
