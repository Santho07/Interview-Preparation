#include<iostream>
using namespace std;
#define Max 1007
int grid[Max][Max], vis[Max][Max];
int N, M;

struct node{
    int x, y, dis;
};
class Queue{
    int topId;
    int frontId;
    struct node arr[Max*Max];
    public:
    Queue() { topId = -1; frontId = 0; }
    void push(int x, int y, int dis){
        topId++;
        arr[topId].x = x;
        arr[topId].y = y;
        arr[topId].dis = dis;
    }
    node front(){return arr[frontId]; }
    void pop(){ frontId++; }
    bool empty(){ return frontId>topId; }
};

int Up[8] = { 0, 1, 1, 0, 1, 0, 0, 1 };
int Down[8] = { 0, 1, 1, 0, 0, 1, 1, 0 };
int Left[8] = { 0, 1, 0, 1, 0, 0, 1, 1 };
int Right[8] = { 0, 1, 0, 1, 1, 1, 0, 0 };

int getCount(int x, int y, int length){
    if(grid[x][y]==0) return 0;

    Queue q;
    q.push(x, y, 1);
    vis[x][y] = 1;
    int cnt = 0;

    while(!q.empty()){
        node hand = q.front(); q.pop();
        x = hand.x; y = hand.y;
        int dist = hand.dis + 1;
        cnt++;
        if(dist>length) continue;
        if (x - 1 >= 0 && Up[grid[x][y]] && Down[grid[x - 1][y]] && !vis[x - 1][y]){
            vis[x - 1][y] = 1;
            q.push(x - 1, y, dist);
        }
        if (x + 1 < N && Down[grid[x][y]] && Up[grid[x + 1][y]] && !vis[x + 1][y]){
            vis[x + 1][y] = 1;
            q.push(x + 1, y, dist);
        }
        if (y - 1 >= 0 && Left[grid[x][y]] && Right[grid[x][y - 1]] && !vis[x][y - 1]){
            vis[x][y - 1] = 1;
            q.push(x, y - 1, dist);
        }

        if (y + 1 < M && Right[grid[x][y]] && Left[grid[x][y + 1]] && !vis[x][y + 1]){
            vis[x][y + 1] = 1;
            q.push(x, y + 1, dist);
        }
    }
    return cnt;
}

int main(){
    int T;
    int R, C, a, b, L, p;

    cin>>T;
    while(T--){
        cin>>N>>M>>R>>C>>L;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>p;
                grid[i][j] = p;
                vis[i][j] = 0;
            }
        }
        cout<<getCount(R, C, L)<<endl;
    }
    return 0;
}
