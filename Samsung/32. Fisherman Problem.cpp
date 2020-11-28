/*
5
10
4 5
6 2
10 2
Minimum Walking Distance: 18
10
8 5
9 1
10 2
Minimum Walking Distance: 25
24
15 3
20 4
23 7
Minimum Walking Distance: 57
39
17 8
30 5
31 9
Minimum Walking Distance: 82
60
57 12
31 19
38 16
Minimum Walking Distance: 313
*/
#include<iostream>
using namespace std;
#define Max 1000
#define INF 1<<30

int n;
int gate[3], fisherman[3];

int abs(int &x){
    return (x>=0)?x:-x;
}
int calc(int i, int j, int k){
    int vis[n+1]={0};
    int cnt = 0, dis = 0;

    for(int p=i; p<(i+fisherman[0])&& p<=n; p++){
        dis+=(abs(p - gate[0])+1);
        vis[p] = 1;
        cnt++;
    }
    for(int p=j; p<(j+fisherman[1])&& p<=n; p++){
        if(!vis[p]) {
            dis+=(abs(p - gate[1])+1);
            cnt++;
            vis[p] = 1;
        }
    }
    for(int p=k; p<(k+fisherman[2])&& p<=n; p++){
        if(!vis[p]){
           dis+=(abs(p - gate[2])+1);
           cnt++;
           vis[p] = 1;
        }
    }
    if(cnt==fisherman[0]+fisherman[1]+fisherman[2]){
        return dis;
    }
    else return INF;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<3; i++){
            cin>>gate[i]>>fisherman[i];
        }
//        cin>>gate[0]>>gate[1]>>gate[2];
//        cin>>fisherman[0]>>fisherman[1]>>fisherman[2];

        int MinWalk = INF;
        int x, y, z;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    if(i!=j && i!=k && j!=k){
                        int d = calc(i, j, k);
                        if(d<MinWalk){
                            MinWalk = d;
                            x = i; y = j; z = k;
                        }
                    }
                }
            }
        }
        if(MinWalk != INF) cout<<"Minimum Walking Distance: "<<MinWalk<<endl;
         cout<<x<<" "<<y<<" "<<z<<endl;
    }
    return 0;
}

