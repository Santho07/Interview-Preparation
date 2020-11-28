#include<bits/stdc++.h>
#define IOS             ios::sync_with_stdio(0); cin.tie(0);
#define pb              push_back
#define mkp             make_pair
#define all(a)          a.begin(), a.end()
#define rall(a)         a.rbegin(), a.rend()
#define maximum(a)      *max_element(all(a))
#define minimum(a)      *min_element(all(a))
#define MAX             (int)2e5+7
using namespace std;
typedef long long LL;
typedef pair<int, int> pi;
typedef pair<LL, LL> pill;
void pyramidreverse(int rows){
    for(int i=1; i<=rows; i++){
        for(int space=0; space<2*(rows-i); space++) putchar(' ');
        for(int j=1; j<i*2; j++) printf("* ");
        putchar('\n');
    }
}
void pyramid(int rows){
    for(int i=rows; i>=1; i--){
        for(int space=0; space<2*(rows-i); space++) putchar(' ');
        for(int j=1; j<i*2; j++)  printf("* ");
        putchar('\n');
    }
}
int main()
{
    IOS;
    int n;
    cin>>n;
    pyramid(n);
    pyramidreverse(n);

}
