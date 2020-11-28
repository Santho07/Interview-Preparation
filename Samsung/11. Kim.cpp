#include<iostream>
using namespace std;
const int N = 20;

int x[N], y[N];
bool vis[N];

int n, ans;
inline int abs(int x){
    return (x>0)?  x: -1*x;
}
int calc(int i, int j){
        return (abs(x[i]-x[j]) + abs(y[i]-y[j]));
}
void findPath(int source, int visited, int dis){

    if(visited==n){
        int d = dis + calc(source, n+1); //dis + last node to home
        if(ans==-1) ans = d;
        else if(d<ans) ans = d; //Minimum distance between all path
    }
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            vis[i] = true;
            findPath(i, visited+1, dis+calc(source, i));
            vis[i] = false;
        }
    }
}
void reset(int n){
    ans = -1;
    for(int i=0; i<n+2; i++) vis[i] = false;
}
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n;
        reset(n);

        cin>>x[0]>>y[0]>>x[n+1]>>y[n+1];
        for(int i=1; i<=n; i++){
            cin>>x[i]>>y[i];
        }
        findPath(0, 0, 0);
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}

