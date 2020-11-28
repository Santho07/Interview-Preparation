#include<iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int vis[MAX];
#define INF 1<<30
int n, Mindis;

int calc(int x, int y){
    int d = x - y;
    if(d<0) d = -d;
    return d;
}

void calculateDistance(int now, int dis, int cars, int liter,  int fillup, int gas){

    if(cars==n){
        if(dis<Mindis){
            Mindis = dis;
        }
        return;
    }
    if(liter<=0) return;

    if(fillup==0 && gas == 1){
        for(int i=1; i<=n; i++){
            if(vis[i]==0 && arr[i]==gas){
                vis[i] = 1;
                //Go to next car
                calculateDistance(i, dis+calc(now, i), cars+1, liter-1, fillup, gas);
                //go to gasoline station
                calculateDistance(i, dis+calc(now, i),cars+1, 2, 1, gas);
                //go to diesel station
                calculateDistance(i, dis+calc(now, i),cars+1, 2, 2, gas);
                vis[i] = 0;
            }
        }
    }
    if(gas==2 && fillup==0){
        for(int i=n; i>0; i--){
            if(vis[i]==0 && arr[i]==gas){
                vis[i] = 1;
                //Go to next car
                calculateDistance(i, dis+calc(now, i),cars+1, liter-1, fillup, gas);
                //go to gasoline station
                calculateDistance(i, dis+calc(now, i),cars+1, 2, 1, gas);
                //go to diesel station
                calculateDistance(i, dis+calc(now, i),cars+1, 2, 2, gas);
                vis[i] = 0;
            }
        }
    }
    if(fillup==1){
        calculateDistance(0, dis+calc(now, 0), cars, 2, 0, 1);
    }
    if(fillup==2){
         calculateDistance(n+1, dis+calc(now, n+1),cars, 2, 0, 2);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        Mindis = INF;

       calculateDistance(0, 0, 0, 2, 0, 1);
       if(Mindis==INF) calculateDistance(n+1,calc(0, n+1),0, 2, 0, 2);

       cout<<"Distance :"<<Mindis<<endl;
    }
}

