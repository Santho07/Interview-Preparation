/*
    Find a cycle, if exists, in a directed graph.
    If there is none, print 0.
    If there is one, print the path starting from the first node of the cycle to the last.
    If there are more than one, print any path.
    1<=N<=100
    Sample Input:
    5
    6 12    //Single loop
    0 1
    0 2
    0 5
    1 3
    1 5
    2 1
    2 4
    3 0
    4 3
    5 0
    5 3
    5 4
    6 12    //Single loop
    0 1
    0 2
    0 5
    1 3
    1 5
    2 0
    2 4
    3 0
    4 3
    5 0
    5 3
    5 4
    6 13       //Self Loop
    0 1
    0 2
    0 5
    1 1
    1 3
    1 5
    2 1
    2 4
    3 0
    4 3
    5 0
    5 3
    5 4
    6 15        // No loop
    0 1
    0 2
    0 3
    0 4
    0 5
    1 2
    1 3
    1 4
    1 5
    2 3
    2 4
    2 5
    3 4
    3 5
    4 5
    6 6             //Single Loop not from origin
    0 1
    1 2
    2 5
    5 1
    2 3
    3 4
    6 5             //Disconnected Components
    1 2
    2 5
    5 1
    2 3
    3 4
    Output:
    0->1->3->0
    0->1->3->0
    1->1
    -1
*/

#include<iostream>
using namespace std;
const int MAX = 1000;

int adj[MAX][MAX];
int color[MAX];
int parent[MAX];
int n;
int cycle_start, cycle_end;

bool dfs(int u){

    color[u] = 1;
    for(int v=0; v<n; v++){
        if(adj[u][v]){
            if(color[v]==0){
                parent[v] = u;
                if(dfs(v)) return true;
            }
            else if(color[v]==1){
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
    int t;
    cin>>t;
    while(t--){
        int e;
        cin>>n>>e;
        reset();
        for(int i=0; i<e; i++){
            int x, y;
            cin>>x>>y;
            adj[x][y] = 1;
        }
        for(int i=0; i<n; i++){
            if(color[i]==0 && dfs(i)){
                break;
            }
        }
        //cout<<cycle_end<<" "<<cycle_start<<endl;
        if(cycle_start==-1) cout<<"-1"<<endl;
        else if(cycle_end==cycle_start) cout<<cycle_end<<" "<<cycle_start<<endl; //self loop
        else{10 14
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
            cout<<cycle_start<<" ";
            print(cycle_end);
            cout<<cycle_start<<endl;
        }
    }

}
