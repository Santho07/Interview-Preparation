/*
3
5 5
1 1 1 1 1
1 0 0 0 1
1 1 1 1 1
1 0 0 0 1
1 1 1 1 1
3
0 1
2 2
4 0
Shortest of the longest Distance: 3 (index 2,0 )
*/
#include<iostream>
using namespace std;
#define MAX 100
#define INF 1<<30
int grid[MAX][MAX], dis[MAX][MAX];
int maxdis[MAX][MAX];

struct node{
    int x,  y;
};
class Queue{
    int topId, frontId;
    node arr[MAX*MAX];
public:
    Queue(){topId=-1, frontId = 0; }
    void push(int x, int y){
        ++topId;
        arr[topId].x = x;
        arr[topId].y = y;
    }
    void pop(){++frontId;}
    node front(){
        return arr[frontId];
    }
    bool empty(){return frontId>topId;}
};
int fx[] = {0, 0, -1, 1};
int fy[] = {-1, 1, 0, 0};
int row, col;

inline bool valid(int x, int y){return (x>=0 && x<row && y>=0 && y<col && grid[x][y]==1); }
void BFS(int x, int y){
    Queue q;
    q.push(x, y);
    dis[x][y] = 0;
    while(!q.empty()){
        node temp = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int tx = temp.x + fx[k];
            int ty = temp.y + fy[k];
            if(valid(tx, ty) && dis[tx][ty]==INF){
                dis[tx][ty] = dis[temp.x][temp.y]+1;
                if(dis[tx][ty]>maxdis[tx][ty]) maxdis[tx][ty] = dis[tx][ty];
                q.push(tx, ty);
            }
        }
    }
}
void reset(int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            dis[i][j] = INF;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>grid[i][j];
                maxdis[i][j] = 0;
            }
        }
        int rare, x, y;
        cin>>rare;
        for(int i=0; i<rare; i++){
            reset(row, col);
            cin>>x>>y;
            BFS(x, y);
        }
        int shortestlong = INF;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(valid(i, j)){
                    if(maxdis[i][j]<shortestlong){
                        shortestlong = maxdis[i][j];
                    }
                }
            }
        }
        cout<<"Shortest of the longest Distance: "<<shortestlong<<endl;
    }
}

