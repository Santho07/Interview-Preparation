/*
There is one spaceship. X and Y coordinate of source of spaceship and destination spaceship is given.
There are N number of wormholes each wormhole has 5 values.
First 2 values are starting co-ordinate of wormhole and after that value no.
3 and 4 represents ending co-ordinate of wormhole
and last 5th value is represents cost to pass through this wormhole.
Now these wormholes are bi-direction.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to
destination co-ordinate using any number of warm-hole.
It is ok if you wont use any wormhole.

Hint:
You can make graph which contain edge between all points and put cost of that edge.
Now apply djikstra algorithm to find minimum distance between source to destination co-ordinate of spaceship.
Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.

5 //number of wormholes
0 1 0 5 5
1 2 2 5 4
3 1 4 1 3
3 3 5 1 2
3 1 7 4 1

0 0 7 5 //source and destination vertex

Minimum distance: 6

*/

#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
#define Max 1000

#define INF 1<<30 //2^30

int holes[Max][5];
int vis[Max];

int n, ans;
int min(int &a, int &b){ return (a<b)?a:b; }
int abs(int &x) {return (x>=0) ? x : -x; }

int distance(int x1, int y1, int x2, int y2){
    int d = abs(x1-x2) + abs(y1-y2);
    return d;
}
void spaceShip(int sx, int sy, int dx, int dy, int dis){
    int d = distance(sx, sy, dx, dy)+dis; //if comes from wormhole d = wormhole to destination + cost of wormhole
    ans = min(ans, d);

    for(int i=0; i<n; i++){
        if(vis[i]==0){
            vis[i] = 1;
            //pass through wormhole is (dis + cost + previous dis)
            //as bidirectional function is called from both ends of wormhole

            int temp = distance(sx, sy, holes[i][0], holes[i][1]) + holes[i][4]+dis;
            spaceShip(holes[i][2], holes[i][3], dx, dy, temp);
            temp = distance(sx, sy, holes[i][2], holes[i][3]) + holes[i][4]+dis;
            spaceShip(holes[i][0], holes[i][1], dx, dy, temp);

            vis[i] = 0; //if spaceship not use this worm hole initially but want to use later.
        }
    }
}
int main(){
    int sx, sy, dx, dy;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++) cin>>holes[i][j]; //5 values for each wormholes
    }
    cin>>sx>>sy>>dx>>dy;
    ans = INF;

    spaceShip(sx, sy, dx, dy, 0);

    cout<<ans<<endl;
}

