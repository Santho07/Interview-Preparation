#include<iostream>
using namespace std;
#define MAX 100
int n;
int adj[MAX][MAX];

class queue{
    int topID;
    int frontID;
    int arr[MAX];
public:
    queue(){topID = -1, frontID=0;}
    void push(int x){arr[++topID] = x;}
    void pop(){frontID++;}
    int front(){return arr[frontID]; }
    bool empty(){return frontID>topID;}
};
bool biColor(int i, int color[]){
    queue q;
    q.push(i);
    if(adj[i][i]) return false;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=1; i<=n; i++){
            if(adj[u][i]){
                if(color[i]==-1){
                    color[i] = 1- color[u];
                    q.push(i);
                }
                else if(color[i]==color[u]) return false;
            }
        }
    }
    return true;
}
int main(){
    int e;
    cin>>n>>e;
    int color[n];

    for(int i=1; i<=n; i++){
        color[i]  = -1;
    }
    for(int i=1; i<=e; i++){
        int a, b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            color[i] = 0;
            if(!biColor(i, color)) { cout<<"-1"<<endl; return 0; }
        }
    }
    for(int i=1; i<=n; i++){
        if(color[i]==0) cout<<i<<" ";
    }
    cout<<endl;
}

