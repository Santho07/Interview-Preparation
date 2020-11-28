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
void addOneinArray(int arr[], int n){

    cout<<n<<endl;
}
void addOne(vector<int> &v){
    int n = v.size();
    int carry = 1;
    for(int i=n-1; i>=0; i--){
        v[i]+=carry;
        carry = v[i]/10;
        v[i] = v[i]%10;
        if(carry==0) break;
    }
    if(carry==1) v.insert(v.begin(), 1);
}
void print(vector<int> &v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
}
int main()
{
    IOS;
    vector<int> v;
    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
//    addOne(v);
//    print(v);
    n = sizeof(arr)/sizeof(arr[0]);
    addOneinArray(arr, n);
}
