/*
8
1 1 1 1 1
2 2 2 2 2
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 2 2 2 2
2 2 0 2 2
0 1 0 2 2
Max_Coins : 5
*/

#include<iostream>
using namespace std;
#define Max 100
int grid[Max][5];
int enemy[25][2];
int num_rows;
bool bombUsed = false;
int cnt, maxCoins;

void destroyEnemies(int start){
  cnt = 0;
  for(int x=start; x<num_rows && x<start+5; x++){
    for(int y=0; y<5; y++){
        if(grid[x][y]==2){
            enemy[cnt][0] = x;
            enemy[cnt][1] = y;
            cnt++;
            grid[x][y] = 0;
        }
    }
  }
}
void restorEnemies(){
    for(int i=0; i<cnt; i++){
        int x = enemy[i][0];
        int y = enemy[i][1];
        grid[x][y] = 2;
    }
}
void go_to(int row, int col, int coins){

    if(col<0 || col>=5) return;
    if(row==num_rows){
       if(coins>maxCoins) maxCoins = coins;
       return;
    }

    if(grid[row][col]==1) coins++;
    else if(grid[row][col]==2){
        if(bombUsed==true){
            //game over
            if(coins>maxCoins) maxCoins = coins;
            return;
        }
        else{
            bombUsed = true;
            destroyEnemies(row);
        }
    }
    go_to(row+1, col, coins);
    go_to(row+1, col-1, coins); //left
    go_to(row+1, col+1, coins); //right

    if(bombUsed==true){
        restorEnemies();
        bombUsed = false;
    }
}
int main(){

    cin>>num_rows;
    for(int i=num_rows-1; i>=0; i--){
        cin>>grid[i][0]>>grid[i][1]>>grid[i][2]>>grid[i][3]>>grid[i][4];
    }
//    for(int i=0; i<num_rows; i++){
//        for(int j=0; j<5; j++) cout<<grid[i][j]<< " ";
//        cout<<endl;
//    }
    maxCoins = 0;

    go_to(0, 2, 0);
    go_to(0, 1, 0);
    go_to(0, 3, 0);

    cout<<"Max_Coins : "<<maxCoins<<endl;
    return 0;
}

