#include<iostream>
using namespace std;
int Min = (int)1e9+7;

void findxy(int n){
    int x, y, d, i, j;
    for(i=1; i*i<=n; i++){
        if(n%i==0){
            j = n/i;
            d = abs(i-j);
            if(d<Min){
                Min = d;
                x = i;
                y = j;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    int n;
    cin>>n;
    findxy(n);
}

