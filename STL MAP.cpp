#include<bits/stdc++.h>
#define IOS             ios::sync_with_stdio(0);
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

int main()
{
    IOS;
    map<int, int> mymap;
    for(int i=0; i<=150; i++){
        mymap[i%50]++;
    }
    mymap.insert({100, 10});
    cout<<mymap[100]<<endl;
    if(mymap.find(70)==mymap.end()) cout<<"Not found"<<endl;
    cout<<mymap[70]<<endl;
    mymap[70] = 7;
    if(mymap.find(70)!=mymap.end()) cout<<"found"<<endl;
    cout<<mymap[70]<<endl;

}
