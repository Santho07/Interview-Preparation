
#include<iostream>
using namespace std;
#define Max 1007

//pipe configuration
//up, down, left, right
int pipe[8][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1}, //pipe 1
    {1, 1, 0, 0}, //pipe 2
    {0, 0, 1, 1}, //pipe 3
    {1, 0, 0, 1}, //pipe 4
    {0, 1, 0, 1}, //pipe 5
    {0, 1, 1, 0}, //pipe 6
    {1, 0, 1, 0}  //pipe 7
};
//direction: up, down, left, right
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};

int N, M;
int grid[Max][Max], vis[Max][Max];

inline bool valid(int x, int y){
    return (x>=0 && x<N && y>=0 && y<M);
}
//only 4 direction is possible to be connected
//up-down, down-up, left-right, right-left
//That is: 0-1, 1-0, 2-3, 3-2

bool connected(int d, int x, int y){
    int p = grid[x][y];
    if(d==0 && pipe[p][1]) return 1;
    else if(d==1 && pipe[p][0]) return 1;
    else if(d==2 && pipe[p][3]) return 1;
    else if(d==3 && pipe[p][2]) return 1;
    else return 0;
}
void getCount(int x, int y, int l){
    vis[x][y] = 1;
    if(l==0) return;
    for(int k=0; k<4; k++){
        int p = grid[x][y];
        if(pipe[p][k]==1){
            int i = x + fx[k];
            int j = y + fy[k];
            if(valid(i, j) && !vis[i][j] && connected(k, i, j)){ //k implies the direction of pipe(x, y)
                vis[i][j] = 1;
                getCount(i, j, l-1);
            }
        }
    }
}
void reset(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j]= 0;
        }
    }
}
int main(){
    int T;
    int R, C, a, b, L, p;

    cin>>T;
    while(T--){
        cin>>N>>M>>R>>C>>L;
        reset(N, M);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>p;
                grid[i][j] = p;
            }
        }
        int cnt = 0;
        if(grid[R][C]==0){
            getCount(R, C, L-1);
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(vis[i][j]==1) cnt++;
                }
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}

