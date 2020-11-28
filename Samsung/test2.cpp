#include<bits/stdc++.h>
using namespace std;

int ar[100],vis[100],n,r,cnt=0,mini = 10000;
int pos[4],fisherman[4],res[4];

int cal_dis()
{
    int spots[n+1];
    memset(spots,0,sizeof(spots));
    int start = res[1];
    int dis=0;
    for(int i=start;i<=(start+fisherman[1]-1) && i<=n;i++){
        spots[i] = 1;
        dis += (abs(i-pos[1]) + 1);
    }

    start = res[2];
    for(int i=start;i<=(start+fisherman[2]-1) && i<=n;i++){
        spots[i] = 2;
        dis += (abs(i-pos[2]) + 1);
    }

    start = res[3];

    for(int i=start;i<=(start+fisherman[3]-1) && i<=n;i++){
        spots[i] = 3;
        dis += (abs(i-pos[3]) + 1);
    }

    int cnt = 0;

    for(int i=1;i<=n;i++){
        if(spots[i]) cnt++;
    }
    if(cnt==(fisherman[1] + fisherman[2] + fisherman[3]) ){
        return dis;
    }
    return 10000;
}


void dfs(int nodes)
{
    if(nodes==3){
        cnt++;
        int idx = 1;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                res[idx++] = ar[i];
            }
        }
        int val = cal_dis();
        mini = min(mini,val);
        return;
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(nodes+1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) ar[i]=i;
    cin>>pos[1]>>pos[2]>>pos[3];
    cin>>fisherman[1]>>fisherman[2]>>fisherman[3];
    dfs(0);
    cout<<mini<<endl;
}
