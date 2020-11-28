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

void printMultiples(){
    int last;
    for(int i=200; i>=1; i--){
        if(i%3==0) { last = i; break; }
    }
    for(int i = last; i>=3; i-=3) cout<<i<<" "; cout<<endl;

    for(int i=200; i>=1; i--){
        if(i%3==0) cout<<i<<" ";
    }
    cout<<endl;

}
int main()
{
    IOS;

    printMultiples();

}
