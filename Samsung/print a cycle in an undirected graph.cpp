/*
6 6
1 2
1 4
2 3
3 4
3 5
5 6
output: 1 4 3 2 1
*/

#include<iostream>
using namespace std;
const int MAX = 1000;
int adj[MAX][MAX];
int color[MAX];
int parent[MAX];
int n;
int cycle_start, cycle_end;

//class stack{
//    int topID;
//    int arr[MAX];
//public:
//    stack(){topID = -1;}
//    void push(int x){arr[++topID] = x;}
//    void pop(){--topID;}
//    int top() {return arr[topID];}
//    bool empty() {return topID<0;}
//
//};
//void print(stack &s){
//    int x = s.top(); s.pop();
//    cout<<x<<" ";
//    while(!s.empty()){
//        int y = s.top(); s.pop();
//        cout<<y<<" ";
//        if(y==x) break;
//    }
//    cout<<endl;
//    exit(0);
//}
bool dfs(int u){
    color[u] = 1;
    for(int v=1; v<=n; v++){
        if(adj[u][v]){
            if(v!=parent[u] && color[v]==0){
                parent[v] = u;
                if(dfs(v)) return true;
            }
            else if(v!=parent[u] && color[v]==1){
                cycle_start = v;
                cycle_end = u;
                return true;
            }
        }
    }
    color[u] = 2;
    return false;
}
void reset(){
    for(int i=0; i<n; i++){
        parent[i] = -1;
        color[i] = 0;
        cycle_start = -1;
        for(int j=0; j<n; j++) adj[i][j] = 0;
    }
}
void print(int v){
    if(parent[v]!=cycle_start){
        print(parent[v]); //print from cycle end to cycle start in reverse order
    }
    cout<<v<<" ";
}
int main(){
    int e;
    cin>>n>>e;
    reset();
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    for(int i=1; i<=n; i++){
        if(color[i]==0 && dfs(i)){
            break;
        }
    }
    if(cycle_start==-1) cout<<"-1"<<endl;
    else if(cycle_end==cycle_start) cout<<cycle_end<<" "<<cycle_start<<endl; //self loop
    else{
        cout<<cycle_start<<" ";
        print(cycle_end);
        cout<<cycle_start<<endl;
    }
}

