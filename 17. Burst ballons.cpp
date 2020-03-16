#include<iostream>
using namespace std;
#define Max 500
int nums[Max];
int opt[Max][Max];
int n;
int maxx(int &a, int &b){
    return ((a>=b) ? a : b);
}
int maxCoins(){
    for(int len=0; len<n; ++len){
        for(int i=0; i+len<n; ++i){
            int j = i + len;
            for(int k=i; k<=j; ++k){
                int left_num = (i==0)? 1 : nums[i-1];
                int right_num = (j==n-1)? 1 : nums[j+1];

                int left_opt = (k==i) ? 0 : opt[i][k-1];
                int right_opt = (k==j)? 0: opt[k+1][j];
                int calc = left_num*nums[k]*right_num + left_opt + right_opt;
                opt[i][j] = maxx(opt[i][j], calc);
            }
        }
    }
    return opt[0][n-1];
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<maxCoins()<<endl;

    return 0;
}

