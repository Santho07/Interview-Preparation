#include<iostream>
using namespace std;
int adj[100][100];
int n;
bool biColor(int i, int color[]){
    if(adj[i][i]) return false;

    bool flag = true;
    for(int j=1; j<=n; j++){
        if(adj[i][j]){
            if(color[j]==-1){
                color[j] = 1 - color[i];
                flag = flag & biColor(j, color);
            }
            else if(color[j]==color[i]) return false;
        }
    }
    return flag;
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
            if(!biColor(i, color)){cout<<"-1"<<endl; return 0;}
        }
    }
    for(int i=1; i<=n; i++){
        if(color[i]==0) cout<<i<<" ";
    }
    cout<<endl;
}

