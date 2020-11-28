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

int main()
{
    IOS;
    int n;
    vector< pair<string, int> > v;
    string binary;
    while(cin>>n){
        int m = (1 << (n + 1));
        n = (1 << (n + 1)) - 1;
        binary = bitset<32>(n).to_string(); //to binary
        cout<<n<<" "<<binary<<endl;
        binary = bitset<32>(m).to_string(); //to binary
        cout<<m<<" "<<binary<<endl;
    }

    unsigned long decimal = bitset<32>(binary).to_ulong();
    cout<<decimal<<"\n";
    return 0;
}
